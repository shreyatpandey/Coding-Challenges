# Apple Wi-Fi Location SDET Interview Preparation
**Role:** Wi-Fi Location Software Development Engineer - In Test
**Focus:** 802.11mc (RTT), Physics of Radio, Sensor Fusion, and Test Automation.

---

## 1. Multipath Propagation & Physics
**Question:** Explain Multipath propagation, its impact on RTT accuracy, and how to test for the "worst-case" scenario.

*   **Concept:** Multipath is when RF signals bounce off walls, floors, and objects. The receiver hears multiple copies of the signal.
*   **Impact on RTT:** Since reflections travel a longer path than the direct line of sight, multipath *always* adds a **positive bias** to the distance (making the device appear further away than it is).
*   **Key Test Case:** **Non-Line-Of-Sight (NLOS)**.
    *   *Setup:* Place Initiator and Responder around a corner or behind a metal door. This forces the device to rely *only* on reflected signals, validating how the algorithm handles extreme bias.

---

## 2. Coding: Cleaning Noisy Distance Data 
**Question:** Write a Python function to process a list of raw distance measurements (containing outliers) and return a clean average.
*   *Input:* `[5.1, 5.2, 5.1, 120.5, 5.3]`

**Ideal Approach (IQR Method):**
Do not use simple Mean/Standard Deviation, as massive outliers (like 120.5m) skew the mean. Use **Interquartile Range (IQR)** or Median filtering.

```python
def clean_distance_data(measurements):
    if not measurements: return 0.0
    
    # Sort and find Percentiles
    sorted_data = sorted(measurements)
    test_len = len(sorted_data)
    q1 = sorted_data[int(test_len * 0.25)]
    q3 = sorted_data[int(test_len * 0.75)]
    
    # Filter using IQR
    iqr = q3 - q1
    lower = q1 - (1.5 * iqr)
    upper = q3 + (1.5 * iqr)
    
    valid = [x for x in measurements if lower <= x <= upper]
    
    return sum(valid) / len(valid) if valid else 0.0
```

---

## 3. Automation Reliability: Infrastructure Failure
**Question:** In a 12-hour stability test, if the Access Point (Responder) crashes at hour 6, how should your automation handle it?

*   **Wrong Answer:** Fail the test and exit. (Wastes 6 hours of testing).
*   **Right Answer:** **Self-Healing Automation**.
    1.  **Detect:** Consecutive timeouts or invalid data.
    2.  **Diagnose:** Try to `ping` the Responder.
    3.  **Recover:** Issue a command to reboot the AP (via PDU/Smart Plug or ADB).
    4.  **Resume:** Continue the test and log the "Infrastructure Event" separately from a DUT (Device Under Test) failure.

---

## 4. Protocol Mechanics & User Privacy
**Question:** In the FTM exchange ($t_1, t_2, t_3, t_4$), who calculates the distance? Why does it matter?

*   **The Math:**
    $$ \text{Distance} = c \times \frac{(t_4 - t_1) - (t_3 - t_2)}{2} $$
    *   *Crucial:* You must subtract $(t_3 - t_2)$ (the processing turnaround time inside the AP), otherwise distance is calculated as thousands of kilometers.
*   **Privacy Architecture:**
    *   The **Phone (Initiator)** calculates the distance.
    *   The Access Point (Responder) *does not know* how far the phone is. It simply replies with timestamps.
    *   This prevents venues (malls, airports) from tracking user location passively without permission.

---

## 5. Sensor Fusion: The "Elevator" Problem
**Question:** If a user goes up 10 floors in a metal elevator (Wi-Fi & GPS lost), what sensor determines the vertical floor change?

*   **The Trap:** It is **NOT GPS** (Signal too weak indoors, vertical accuracy is poor/ +/- 20m).
*   **The Answer:** The **Barometer** (Air Pressure Sensor).
    *   Pressure drops linearly with altitude. The Sensor Fusion engine uses the Accelerometer to confirm "movement" and Barometer to calculate "Delta Height".
*   **How to Test:** Use a generic Pressure Chamber (box with air pump) to simulate altitude changes while the phone is stationary.

---

## 6. Real-World Debugging (Lab vs. Field)
**Question:** Why does location work in the Lab but jump randomly (+/- 50m) in high-density cities like Tokyo?

*   **Cause 1 (Congestion):** High AP density leads to **Co-Channel Interference (CCI)** and collisions, corrupting the long FTM packet exchanges.
*   **Cause 2 (Interop):** "Cheap" consumer routers often have poor clock stability or lie about their LCI (Location Configuration Information). A router might claim it supports 802.11mc but provides trash timestamps.
*   **Debugging Data Needed:**
    *   **Scan Dump:** To identify specific AP vendors causing issues.
    *   **LCI Data:** To check if an AP is broadcasting incorrect Latitude/Longitude.
    *   **Raw Timestamps:** Analyzing $(t_3 - t_2)$ consistency to detect processing lag in the AP.
