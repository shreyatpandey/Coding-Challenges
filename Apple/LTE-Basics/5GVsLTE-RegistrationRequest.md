# 5G Registration Request vs. LTE Attach Request

## Table of Contents
1. [Procedural Overview](#procedural-overview)
2. [Message Structure Comparison](#message-structure-comparison)
3. [Key Differences](#key-differences)
4. [Network Architecture Context](#network-architecture-context)
5. [Security Processing Differences](#security-processing-differences)
6. [Message Flow Comparison](#message-flow-comparison)
7. [State Machine Differences](#state-machine-differences)
8. [Practical Differences in Implementation](#practical-differences-in-implementation)
9. [Interview Q&A](#interview-qa)

---

## Procedural Overview

### LTE Attach Request

```
UE → eNB → MME

Purpose: Initial network attachment, establish EPS (EPS Bearer Service)
Triggers: Power-on, out-of-service recovery, manual search
State Machine: EMM (EPS Mobility Management) states
Establishment: Dedicated signaling connection (RRC → S1-AP → MME)

Attach Type (in message):
├─ EPS attach
├─ Combined EPS/IMSI attach (2G/3G coexistence)
└─ Emergency attach (limited service)
```

### 5G Registration Request

```
UE → gNB → AMF (Access and Mobility Management Function)

Purpose: Register with 5GC (5G Core), establish service connectivity
Triggers: Power-on, out-of-service, mobility from LTE, manual search
State Machine: 5GMM (5G Mobility Management) states
Establishment: N1 connection (RRC → NG-AP → AMF via gNB)

Registration Type (in message):
├─ Initial Registration
├─ Mobility Registration Update (MRU)
├─ Periodic Registration Update (PRU)
└─ Emergency Registration
```

---

## Message Structure Comparison

### LTE Attach Request

```
┌─────────────────────────────────────────────────┐
│ ATTACH REQUEST (Message Type: 0x41)             │
├─────────────────────────────────────────────────┤
│ Mandatory:                                      │
│  ├─ EPS Attach Type (1 byte)                   │
│  │  ├─ 001: EPS attach                          │
│  │  ├─ 010: Combined EPS/IMSI attach            │
│  │  └─ 100: EPS emergency attach                │
│  │                                              │
│  ├─ NAS Key Set Identifier (1 byte)            │
│  │  ├─ Bits 7: Spare                            │
│  │  ├─ Bits 6-4: KSI (3 bits, 0-7)             │
│  │  └─ Bits 3-0: ASME Key Set Identifier       │
│  │                                              │
│  ├─ EPS Mobile Identity (variable)             │
│  │  ├─ IMSI (0b001)                             │
│  │  ├─ GUTI (0b110)                             │
│  │  └─ IMEI (0b011) - for emergency only        │
│  │                                              │
│  └─ UE Network Capability (variable)            │
│     ├─ Ciphering alg support (4 algs)           │
│     ├─ Integrity alg support (4 algs)           │
│     └─ Other: UEA0, UIA0, ProSe, etc.           │
│                                                 │
│ Optional (IEs):                                 │
│  ├─ Old PTMSI Signature (3 bytes)               │
│  ├─ Old LAI (Location Area Identity - 5 bytes)  │
│  ├─ TMSI Status                                 │
│  ├─ DRX Parameter                               │
│  ├─ MS Network Capability (2G/3G)               │
│  ├─ Old GUTI (if known)                         │
│  ├─ Additional GUTI                             │
│  ├─ MS Classmark 3                              │
│  ├─ Supported Codec List                        │
│  ├─ Device Properties                           │
│  ├─ Old Location Area ID                        │
│  └─ Extended DRX Parameters                     │
└─────────────────────────────────────────────────┘

Total: ~50-100 bytes typical
```

### 5G Registration Request

```
┌──────────────────────────────────────────────────┐
│ REGISTRATION REQUEST (Message Type: 0x41)        │
├──────────────────────────────────────────────────┤
│ Mandatory:                                       │
│  ├─ Registration Type (1 byte)                  │
│  │  ├─ Bits 7-4: Follow-On Request Pending (1)  │
│  │  ├─ Bits 3: Spare                             │
│  │  └─ Bits 2-0: Reg Type (3 bits)               │
│  │     ├─ 001: Initial Registration              │
│  │     ├─ 010: Mobility Reg Update (inter-gNB)   │
│  │     └─ 011: Periodic Reg Update               │
│  │                                               │
│  ├─ 5G-GUTI or 5G-S-TMSI (variable)             │
│  │  ├─ SUPI (Subscription Permanent ID)          │
│  │  │  ├─ IMSI format (0b00)                      │
│  │  │  ├─ Network Specific Identifier (0b01)      │
│  │  │  └─ GCI (0b10)                              │
│  │  └─ 5G-GUTI: GUAMI (2 + 3 bytes) + TMSI (4)   │
│  │                                               │
│  ├─ NAS Key Set Identifier (1 byte)             │
│  │  ├─ Bits 7: TSC (True/False)                  │
│  │  └─ Bits 6-4: NAS Key Set ID                  │
│  │                                               │
│  ├─ 5GS Registration Capability (variable)      │
│  │  ├─ LTE Positioning Protocol Capability       │
│  │  ├─ Multiple DRX Support                      │
│  │  ├─ N3IWF Support                             │
│  │  ├─ Satellite Access Capability               │
│  │  └─ NTN Capability (3GPP Release 18+)         │
│  │                                               │
│  └─ UE Security Capability (variable)            │
│     ├─ 5G-EA (Encryption algs: 8 algs supported) │
│     ├─ 5G-IA (Integrity algs: 8 algs supported)  │
│     ├─ EEA Support (LTE backward compat)         │
│     ├─ EIA Support (LTE backward compat)         │
│     └─ ORYX (Originating ciphering)              │
│                                                  │
│ Optional (IEs):                                  │
│  ├─ Old 5G-GUTI                                  │
│  ├─ Additional GUTI                              │
│  ├─ Allowed NSSAI (Network Slice Sel Assist)    │
│  ├─ UE Request Type (Single Reg/Dual Reg)       │
│  ├─ Device Properties                            │
│  ├─ DRX Parameter (10ms/20ms/32ms/64ms/128ms)   │
│  ├─ EPS-NAS Security Algorithms (if from LTE)    │
│  ├─ Payload Container (for Multi-Protocol)       │
│  ├─ LADN Indication                              │
│  ├─ Network Slicing Indication                   │
│  ├─ Old S1UE-XMSI (if from LTE)                  │
│  ├─ Additional Configuration Indication          │
│  ├─ Preferred PLMN List (operator preference)    │
│  └─ 5GS Tracking Area Identity (5G-TAI)          │
└──────────────────────────────────────────────────┘

Total: ~80-150 bytes typical (more IEs than LTE)
```

---

## Key Differences

| **Aspect** | **LTE Attach Request** | **5G Registration Request** |
|---|---|---|
| **PDU Session** | Established via separate PDN Connectivity Request after attach | PDU Sessions can be established in parallel with registration (Service Request with Payload Container) |
| **Identity** | GUTI (old) or IMSI | 5G-GUTI or SUPI (IMSI variant) with GUAMI |
| **Security** | KASME (LTE key) + EEA0/1/2, EIA1/2 | KAUSF + 5G-EA0/1/2/3, 5G-IA0/1/2/3 (more algorithms) |
| **State Machine** | EMM (Deregistered/Registered/Tracking Area Updating) | 5GMM (Deregistered/Registered-Init/Registered) |
| **TAI** | TAI (Tracking Area Identity) - 2G heritage | 5G-TAI + PLMN ID in 5G-GUTI |
| **Slicing** | N/A | NSSAI (Network Slice Selection Assistance Info) included |
| **DRX Flexibility** | Fixed DRX cycles (e.g., 1.28s, 2.56s) | Multiple DRX timers, granular values (10-128ms) |
| **Dual Connectivity** | N/A | Dual registration (5G-RAN + 3GPP access) possible |
| **Roaming** | IMSI + PLMN routing | SUPI Concealment mandatory in roaming scenarios |
| **Core Network** | MME (Mobility Management Entity) | AMF (Access and Mobility Function) + UDM |
| **QoS** | EPS QCI (9 classes) | 5QI (5G QoS Indicator) + Flow QoS Identifier |

---

## Network Architecture Context

### LTE Architecture (EPS)

```
UE ↔ eNB (E-UTRAN) ↔ S-GW (Serving GW) ↔ P-GW (PDN GW)
                    ↔ MME ↔ HSS (Home Subscriber Server)
                    ↔ PCRF (Policy & Charging Rules Function)

Attach creates:
├─ Control plane path: UE → MME → HSS
├─ User plane path: UE → eNB → S-GW → P-GW → PDN
└─ S1 Interface (eNB ↔ MME)
```

### 5G Architecture (5GC)

```
UE ↔ gNB (RAN) ↔ UPF (User Plane Function)
               ↔ AMF ↔ UDM (Unified Data Management)
               ↔ PCF (Policy & Charging Function)
               ↔ AUSF (Authentication Server Function)

Registration creates:
├─ Control plane: UE ↔ AMF (NG-C interface via gNB)
├─ User plane: UE ↔ gNB ↔ UPF (NG-U interface)
├─ AMF-UDM: User profile retrieval
└─ Service Request can establish PDU sessions in parallel
```

---

## Security Processing Differences

### LTE Attach Security

```
1. UE sends Attach Request (no ciphering yet)
2. Network executes EPS AKA (Authentication and Key Agreement)
   ├─ HSS generates: RAND, XRES, K_ASME, AUTN
   ├─ Sends to UE via MME
   └─ K_ASME (256-bit): Master key for all crypto
3. UE derives: K_NASenc (Cipher key), K_NASint (Integrity key)
4. Network sends: Attach Accept (encrypted + integrity protected)
5. UE establishes AS (Access Stratum) security with eNB
   ├─ K_eNB derived from K_ASME
   └─ Uplink/Downlink K_RRC and K_PDCP keys

Ciphering Algorithm: EEA0 (no cipher), EEA1 (SNOW 3G), EEA2 (AES-CTR)
Integrity Algorithm: EIA1 (SNOW 3G), EIA2 (AES-CMAC)
```

### 5G Registration Security (3GPP TS 33.501)

```
1. UE sends Registration Request (optional ciphering, SUPI concealment)
2. Network executes 5G AKA (AUSF)
   ├─ UDM generates: RAND, HXRES*, K_AUSF, AUTN
   ├─ Sends to UE via AMF
   └─ K_AUSF (256-bit): Master key in 5GC
3. UE derives: K_AMF (for NAS security)
4. AMF derives: K_NASenc, K_NASint from K_AMF
5. UE establishes AS security with gNB
   ├─ K_gNB derived from K_AMF
   ├─ K_RRC (ciphering), K_RRC_int (integrity)
   └─ K_PDCP (ciphering), K_PDCP_int (integrity)

Ciphering Algorithms: 5G-EA0 (NULL), 5G-EA1 (SNOW 3G), 5G-EA2 (AES-CTR), 5G-EA3 (ZUC)
Integrity Algorithms: 5G-IA0 (NULL), 5G-IA1 (SNOW 3G), 5G-IA2 (AES-CMAC), 5G-IA3 (ZUC-CMAC)

Additional: ZUC support (Chinese telecom requirement, stronger than SNOW)
```

### Key Derivation Example

```
LTE:
K_NASenc = KDF(K_ASME, 0x15, Alg ID, Direction)
K_NASint = KDF(K_ASME, 0x16, Alg ID, Direction)

5G:
K_AMF = KDF(K_AUSF, "5G-SA", SUPI, Routing Indicator)
K_NASenc = KDF(K_AMF, 0x69, Alg ID, Direction)
K_NASint = KDF(K_AMF, 0x6A, Alg ID, Direction)
```

---

## Message Flow Comparison

### LTE Attach Flow

```
UE                          eNB                 MME                 HSS
│                            │                   │                   │
├──── RRC Setup Request ─────→│                   │                   │
│                            │                   │                   │
│←─── RRC Setup Complete ────│                   │                   │
│                            │                   │                   │
├─ Attach Request (NAS) ────→│                   │                   │
│ (GUTI or IMSI, no cipher)  │                   │                   │
│                            ├── S1AP Setup ────→│                   │
│                            │   (Attach Req)    │                   │
│                            │                   ├── Auth Info Req. ─→│
│                            │                   │                   │
│                            │                   │←─ Auth Info Resp. ─│
│                            │                   │  (RAND, XRES, etc)│
│                            │                   │                   │
│←──── Auth Request (NAS) ───│←── S1AP ─────────│                   │
│ (RAND, AUTN)               │                   │                   │
│                            │                   │                   │
├──── Auth Response (NAS) ───→│                   │                   │
│ (RES - response to RAND)    │                   │                   │
│                            ├─→ Auth Validation │                   │
│                            │   (RES == XRES)   │                   │
│                            │                   │                   │
├─ RRC Sec Cmd (ciphering) ─→│                   │                   │
│ (K_eNB derived from K_ASME)│                   │                   │
│                            │                   │                   │
├─ RRC Sec Complete ────────→│                   │                   │
│ (AS security established)  │                   │                   │
│                            │                   │                   │
│←─── Attach Accept (NAS) ───│←── S1AP ─────────│  ← Update Profile  │
│ (GUTI, TAI, etc)           │  (encrypted)      │                   │
│                            │                   │                   │
├──── Attach Complete ──────→│                   │                   │
│ (encrypted NAS)            │                   │                   │

Total time: ~200-400ms (with ciphering, auth, RRC setup)
```

### 5G Registration Flow (Simplified)

```
UE                          gNB                 AMF                AUSF/UDM
│                            │                   │                   │
├──── RRC Setup Request ─────→│                   │                   │
│                            │                   │                   │
│←─── RRC Setup Complete ────│                   │                   │
│                            │                   │                   │
├─ Reg Request (NAS) ───────→│                   │                   │
│ (5G-GUTI or SUPI, optional │  (ciphered NAS   │                   │
│  cipher if ID concealment) │   in secure PDU) │                   │
│                            │                   │                   │
│                            ├─ NG-AP ─────────→│                   │
│                            │ (Reg Req)         │                   │
│                            │                   ├─ 5G AKA Req ─────→│
│                            │                   │                   │
│                            │                   │←─ 5G AKA Resp ────│
│                            │                   │ (K_AUSF, AUTN)    │
│                            │                   │                   │
│←─── Auth Request (NAS) ────│←─ NG-AP ────────│                   │
│ (RAND, AUTN)               │  (encrypted)      │                   │
│                            │                   │                   │
├──── Auth Response (NAS) ───→│                   │                   │
│ (RES* derived from HXRES*) │ (encrypted)       │                   │
│                            ├─→ Validate RES*  │                   │
│                            │                   │                   │
├─ RRC Sec Cmd (K_gNB) ─────→│                   │                   │
│ (NAS/AS security)          │                   │                   │
│                            │                   │                   │
├─ RRC Sec Complete ────────→│                   │                   │
│                            │                   │                   │
│←─── Reg Accept (NAS) ──────│←─ NG-AP ────────│                   │
│ (5G-GUTI, NSSAI, etc)      │ (encrypted)       │                   │
│ (Allowed NSSAI)            │                   │                   │
│                            │                   │                   │
├──── Reg Complete ─────────→│                   │                   │
│ (PDU sessions may          │                   │                   │
│  be established in         │                   │                   │
│  parallel with Payload     │                   │                   │
│  Container IEs)            │                   │                   │

Total time: ~150-300ms (often faster than LTE due to parallel PDU session setup)
```

---

## State Machine Differences

### LTE EMM (EPS Mobility Management) States

```
┌──────────────┐
│ DEREGISTERED │  (Initial state)
│              │
│ 1. Limited   │  (No PLMN, emergency only)
│ 2. Normal    │  (Full normal service)
└──────┬───────┘
       │ Attach Request
       ↓
┌──────────────────┐
│ REGISTERED       │  (Attached to network)
│                  │
│ 1. Normal        │  (Normal operation)
│ 2. Limited       │  (Degraded PLMN service)
│ 3. Attempting    │  (Attempt to attach)
└──────┬───────────┘
       │ Detach Request / Out of service
       ↓
┌──────────────┐
│ DEREGISTERED │
└──────────────┘

TAU (Tracking Area Update) keeps UE registered without full attach
```

### 5G 5GMM (5G Mobility Management) States

```
┌──────────────┐
│ 5GMM-IDLE    │  (Powered on, not registered)
│              │
│ 1. Limited   │  (No PLMN connectivity)
│ 2. Updating  │  (In progress)
└──────┬───────┘
       │ Registration Request
       ↓
┌────────────────────┐
│ 5GMM-REGISTERED    │  (Registered with network)
│                    │
│ 1. Normal          │  (Normal operation)
│ 2. Non-3GPP Access │  (Via non-3GPP e.g., WiFi)
│ 3. Limited         │  (Degraded service)
└────────┬───────────┘
         │ Deregistration / Out of service
         ↓
┌──────────────┐
│ 5GMM-IDLE    │
└──────────────┘

MRU (Mobility Registration Update) for intra-5G mobility
PRU (Periodic Registration Update) every T3512 timer expiry
```

---

## Practical Differences in Implementation

| **Scenario** | **LTE Behavior** | **5G Behavior** |
|---|---|---|
| **Dual Connectivity** | Requires active LTE attach + DC setup | Can register to 5G + LTE simultaneously (dual registration) |
| **Network Slicing** | Not supported | NSSAI included in reg, per-slice AMF selection |
| **QoS Mapping** | QCI 1-9 fixed classes | 5QI + per-flow QoS parameters (much more flexible) |
| **Idle Time Battery** | DRX timers fixed (1.28s, 2.56s, 5.12s) | Flexible DRX (10ms-2.56s granularity) |
| **Roaming** | IMSI visible to serving network | SUPI concealed (5G-S-TMSI used), only revealed to home network |
| **PDU Session** | Established separately after attach | Can be established during registration via Service Request |
| **Mobility** | Full TAU with authentication | MRU reuses keys (faster), async handover possible |
| **Emergency** | Limited attach → No data | Dedicated emergency slice possible (with ciphering) |

---

## Interview Q&A

### Q: Why does 5G use separate AUSF instead of keeping HSS as MME did?

**A:** Separation of concerns:
- **AUSF** handles only authentication (5G-AKA execution, key derivation)
- **UDM** stores subscription (replaces HSS), provides user profiles
- **AMF** handles mobility only
- This architecture allows:
  - Distributed network slicing (per-slice AMFs)
  - Load balancing of authentication
  - Roaming flexibility (home AUSF, visited AMF)
  - Easier integration with non-3GPP access (WiFi, fixed broadband)

### Q: Why is SUPI concealment important in 5G but not emphasized in LTE?

**A:** Privacy/security:
- LTE's IMSI protection was weak (intercepted at initial attach)
- 5G mandates SUPI concealment in untrusted networks (roaming)
- UE sends randomized 5G-S-TMSI instead, only revealed to home network after ciphering
- Prevents location tracking by untrusted serving networks

### Q: Can a UE perform 5G registration while still attached to LTE?

**A:** Yes, and this is a common transition scenario:
- UE registers to 5G (dual registration) while keeping LTE attachment
- Can transfer PDU sessions from LTE to 5G (one at a time)
- AMF coordinates with MME via N26 interface
- Allows gradual migration without service interruption

### Q: Why does 5G allow PDU sessions during registration (Service Request) but LTE requires separate PDN Connection?

**A:** Latency optimization:
- LTE: Attach (control) → PDN Connection (control) → Data flow (~400ms)
- 5G: Registration + Service Request with Payload Container (simultaneous) (~150-200ms)
- 5G supports multi-protocol payload containers (e.g., both NAS and DNS in one message)
- Faster time-to-service for latency-sensitive applications (URLLC)

---

## Summary

The transition from LTE's Attach Request to 5G's Registration Request reflects a fundamental shift in network architecture:

- **LTE** emphasizes bearer-based connectivity with separated control/user planes
- **5G** emphasizes service-based architecture with network slicing and flexibility

Both serve the same fundamental purpose (network registration), but 5G's design accommodates higher bandwidth, lower latency, network slicing, and advanced security features required for next-generation wireless applications.
