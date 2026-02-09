# Apple Wi-Fi SDET Interview Prep - Protocols & Systems

## 1. 802.11 Connection State Machine (The "Connect to Wi-Fi" Flow)

**Scenario:** An iPhone connects to a WPA2/WPA3 **Home** Router.

### Correct Sequence:
1.  **Scanning (Discovery):**
    *   **Active:** Phone sends **Probe Requests**. AP sends **Probe Response**.
    *   **Passive:** Phone listens for **Beacons**.
2.  **Authentication (L2):**
    *   `Authentication Request` -> `Authentication Response`.
    *   *Note:* In modern WPA2, this is "Open System" authentication (essentially a formality). No password is checked yet.
3.  **Association:**
    *   `Association Request` -> `Association Response`.
    *   The radio link is established, but the port is blocked not allowing data.
4.  **EAPOL 4-Way Handshake (Security/Encryption):**
    *   The **PTK (Pairwise Transient Key)** is generated here.
    *   This is where the Password (PSK) is actually verified.
5.  **DHCP (DORA):**
    *   **Only after** encryption is established does the device request an IP address.

### The "Incorrect Password" Trap
**Question:** If the user types the wrong password, how does the protocol signal this?
*   **Myth:** The AP sends a "Bad Password" error code.
*   **Reality:**
    1.  **Msg 1:** AP sends Anonce (Random Number).
    2.  **Msg 2:** Phone derives keys from its Password + Anonce. It sends back Snonce + **MIC (Message Integrity Code)**.
    3.  **The Failure:** The AP calculates what the MIC *should* be. If the Password is wrong, the MICs do not match.
    4.  **Result:** The AP **silently drops** the packet (or sends a generic Deauth). It *never* sends Msg 3.
    5.  **User Experience:** The Phone times out waiting for Msg 3 and displays "Incorrect Password".

### Enterprise vs. Personal
*   **WPA-Personal (Home):** Uses a Pre-Shared Key (Password). 4-Way Handshake.
*   **WPA-Enterprise (Office):** Uses **802.1X** / EAP. Requires a **RADIUS Server** and usually **Certificates**. Involves an "Identity Request/Response" phase before the 4-Way Handshake.

---

## 2. Coding: Management Frame Parsing (TLV)
**Task:** Parse a byte stream of [Tag, Length, Value] from a Wi-Fi Management Frame.

### Key Considerations:
*   **Variable Step Loop:** You cannot use a simple `for` loop with a step of 3. You must read the `Length` byte to know where the next Tag starts.
*   **Safety Checks:** Always check `if i + length < total_size` to prevent buffer overflows on malformed packets.
*   **Data Structure:** Use a List of Dicts, not a single Dict (to allow multiple tags of the same ID).

```python
def tlv_parser(tlv_data):
    items = []
    i = 0
    while i < len(tlv_data):
        # Boundary Check 1: Header exists?
        if i + 1 >= len(tlv_data): break 
        
        tag = tlv_data[i]
        length = tlv_data[i + 1]
        
        # Boundary Check 2: Payload exists?
        start = i + 2
        end = start + length
        if end > len(tlv_data): break 
        
        value = tlv_data[start:end]
        items.append({"tag": tag, "length": length, "value": value})
        i = end
    return items
```

---

## 3. Physics & RF Testing

### The "Shielded Box" Anomaly
**Scenario:** A controlled RF box defines a distance of 10m. One reading jumps to 150m.
*   **Cause:** **Multipath (Reflections)**. The signal bounced off the metal walls many times before reaching the receiver.
*   **Physics:** Reflections *always* add distance (positive bias). They never subtract distance.
*   **Test Strategy:** Do not failing a device for a single glitch (physics is physics). Use "Retry/Regression" logic or Median filtering.

---

## 4. Sensor Fusion & Navigation

### The "Stationary Drift" Bug
**Scenario:** Blue dot works while walking, but jitters/teleports when standing still.
*   **The Problem:** Wi-Fi RTT always has noise (+/- 1-2m). If the filter relies solely on Wi-Fi when stopped, the dot will jump.
*   **The Fix:** **Zero Velocity Update (ZUPT)** or **Static Detection**.
    *   The OS must use the **Accelerometer** to detect "Zero Movement".
    *   When Static: **Lock** the position (High Confidence in IMU). Ignore small Wi-Fi changes.

---

## 5. Wi-Fi Generations Comparison (Roadmap)

| Feature | **Wi-Fi 6 / 6E (802.11ax)** | **Wi-Fi 7 (802.11be)** | **Wi-Fi 8 (802.11bn)** |
| :--- | :--- | :--- | :--- |
| **Core Goal** | **Efficiency** (High Density) | **Throughput & Latency** (AR/VR) | **Reliability** (UHR - Ultra High Reliability) |
| **Killer Feature** | **OFDMA** (Sub-dividing channels) | **MLO** (Multi-Link Operation) | **Co-BF** (Coordinated Beamforming between APs) |
| **Channel Width** | 160 MHz | **320 MHz** | 320 MHz (Focus is on reuse, not width) |
| **SDET Focus** | Testing Resource Unit (RU) scheduling. | Testing simultaneous band usage (2.4+5+6GHz). | Testing multi-AP interference coordination. |

*   **Wi-Fi 7 MLO (Multi-Link Operation):** Allows a device to connect to multiple bands (e.g., 5GHz + 6GHz) *simultaneously* for aggregation (speed) or redundancy (reliability).
*   **Wi-Fi 8 (Future):** Focuses on **Coordinated Spatial Reuse**. Your AP talks to your neighbor's AP to align transmission slots, preventing interference without user intervention.
