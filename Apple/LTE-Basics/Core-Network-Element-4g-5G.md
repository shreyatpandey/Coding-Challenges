# Core Network Elements of LTE/4G and 5G

## Table of Contents
1. [LTE/4G Architecture](#lte4g-architecture)
2. [5G Architecture](#5g-architecture)
3. [Key Differences](#key-differences)
4. [Element Comparison](#element-comparison)

---

## LTE/4G Architecture

### Network Layout

```
UE ↔ eNB ↔ S-GW ↔ P-GW
           ↔ MME ↔ HSS
           ↔ PCRF
```

### Core Network Elements

#### 1. **eNB (evolved NodeB)**
- **Purpose:** Base station that connects User Equipment (UE) to the network
- **Function:** Wireless access point, handles RRC (Radio Resource Control)
- **Role:** First contact point for mobile devices

#### 2. **MME (Mobility Management Entity)**
- **Purpose:** Control plane anchor for the network
- **Functions:**
  - User authentication and authorization
  - Location tracking and updates
  - Handover management between eNBs
  - Connection establishment and tear-down
  - Paging (calling the UE when data arrives)
- **Key Interface:** S6a (connects to HSS via Diameter protocol)

#### 3. **S-GW (Serving Gateway)**
- **Purpose:** Local user plane anchor
- **Functions:**
  - Routes user data (internet traffic)
  - Serves as anchor during handovers between eNBs
  - Buffers downlink data when UE is in idle mode
  - Reports usage for charging
- **Key Interfaces:**
  - S1-u: Connects to eNB
  - S5: Connects to P-GW

#### 4. **P-GW (PDN Gateway)**
- **Purpose:** Gateway to external networks
- **Functions:**
  - Connects to public internet and external PDNs (Packet Data Networks)
  - Allocates IP addresses to UEs
  - Enforces QoS policies (via PCRF)
  - Deep packet inspection and traffic filtering
- **Key Interface:** SGi (to external networks/internet)

#### 5. **HSS (Home Subscriber Server)**
- **Purpose:** Centralized database of subscriber information
- **Functions:**
  - Stores IMSI, phone number (MSISDN), and secret key (K)
  - Maintains authentication vectors for AKA (Authentication and Key Agreement)
  - Tracks subscriber location (which MME is serving the UE)
  - Stores subscription profile (what services user is allowed to use)
  - Handles roaming permissions
- **Key Interface:** S6a (connects to MME via Diameter)

#### 6. **PCRF (Policy & Charging Rules Function)**
- **Purpose:** Network policy enforcement
- **Functions:**
  - Decides QoS policies based on service (voice, video, data)
  - Sets bandwidth limits and priority levels
  - Manages charging rules
  - Communicates policies to P-GW
- **Key Interface:** Gx (connects to P-GW via DIAMETER)

---

## 5G Architecture

### Network Layout

```
UE ↔ gNB ↔ UPF
          ↔ AMF ↔ UDM
          ↔ PCF
          ↔ AUSF
```

### Core Network Elements

#### 1. **gNB (5G New Radio Base Station)**
- **Purpose:** Next-generation base station with improved efficiency
- **Function:** Wireless access point with better spectral efficiency than eNB
- **Improvements:** Lower latency, higher throughput, better power efficiency

#### 2. **AMF (Access and Mobility Management Function)**
- **Purpose:** Replaces MME; handles access and mobility in 5G
- **Functions:**
  - UE registration and authentication
  - Location management and updates
  - Mobility management and handovers
  - Session management trigger
  - Paging and connection management
  - Security context handling
- **Key Interfaces:**
  - N1 (to UE via gNB)
  - N2 (to gNB - NG-C interface)

#### 3. **UPF (User Plane Function)**
- **Purpose:** Unified user plane processing (replaces S-GW and P-GW)
- **Functions:**
  - Packet filtering and forwarding
  - QoS handling
  - Charging and usage reporting
  - Anchor point for mobility (local or remote UPF selection)
  - Connection to external networks
- **Key Interfaces:**
  - N3 (to gNB - NG-U interface)
  - N6 (to external networks)
  - N9 (between UPFs for inter-operator roaming)

#### 4. **UDM (Unified Data Management)**
- **Purpose:** Replaces HSS; centralized subscriber data repository
- **Functions:**
  - Stores subscriber credentials and authentication vectors
  - Maintains subscription profiles
  - Manages roaming and IMSI
  - Provides authorization policies
- **Supports:**
  - Multiple IMSI formats
  - Network slicing with different subscriptions
  - Roaming with subscriber privacy protection

#### 5. **PCF (Policy & Charging Function)**
- **Purpose:** Unified policy and charging enforcement (replaces PCRF)
- **Functions:**
  - Defines QoS policies based on applications and network slices
  - Manages charging rules
  - Enforces usage limits
  - Coordinates with UPF for policy implementation
- **Enhancement:** More fine-grained QoS control with 5QI (5G QoS Indicator)

#### 6. **AUSF (Authentication Server Function)**
- **Purpose:** Dedicated authentication and key generation
- **Functions:**
  - Performs 5G AKA (Authentication and Key Agreement)
  - Generates authentication vectors (RAND, HXRES*, AUTN)
  - Derives master key (K_AUSF)
  - Handles authentication with UDM
- **Improvement:** Separate from UDM for better security isolation

---

## Key Differences

| Aspect | LTE/4G | 5G |
|--------|--------|-----|
| **Signaling Architecture** | Centralized (via MME) | Distributed, Service-based |
| **User Plane** | Dual Gateway (S-GW + P-GW) | Unified (UPF) |
| **Master Key** | K_ASME (from HSS) | K_AUSF (from UDM via AUSF) |
| **Network Slicing** | Not supported | NSSAI (Network Slice Selection) |
| **QoS Indicator** | EPS QCI (9 classes) | 5QI (5G QoS Indicator) + Flow ID |
| **Authentication Server** | Part of HSS | Separate (AUSF) |
| **Subscriber Database** | HSS | UDM (more advanced) |
| **Core Flexibility** | Fixed topology | Service-based, modular |
| **Latency** | ~100ms | ~1-10ms (lower) |
| **Routing** | GW-centric | Session-based with UPF |

---

## Element Comparison Table

| **Function** | **LTE/4G** | **5G** | **Notes** |
|---|---|---|---|
| Access Point | eNB | gNB | gNB has better efficiency |
| Mobility/Session Mgmt | MME | AMF | Clearer separation in 5G |
| User Data Routing | S-GW + P-GW | UPF | Unified in 5G |
| Authentication | HSS (integrated) | AUSF (separate) | Better security design |
| Subscriber Data | HSS | UDM | More flexible in 5G |
| Policy Enforcement | PCRF | PCF | More granular in 5G |
| Protocol | Diameter | HTTP/2 + REST APIs | Modern protocols in 5G |

---

## Summary

**LTE/4G** uses a **gateway-centric architecture** with dedicated elements for mobility (MME), data routing (S-GW, P-GW), and subscriber management (HSS). It's hierarchical and centralized.

**5G** uses a **service-based architecture** with unified functions that can be deployed modularly:
- AMF handles mobility
- UPF handles data (single unified element)
- UDM + AUSF handle authentication and subscription
- PCF handles policies

This makes 5G more flexible, scalable, and adaptable to different deployment scenarios (standalone, non-standalone, private networks, etc.).
