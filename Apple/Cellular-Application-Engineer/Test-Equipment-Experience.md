# Test Equipment Experience

## 18. Spectrum Analyzer: Identifying Interference

### How to Use a Spectrum Analyzer:

1. **Setup**
   - Connect the antenna or probe to the spectrum analyzer input
   - Set the center frequency to the band of interest (e.g., 2.4 GHz for LTE Band 7)
   - Configure span width to view the entire band (e.g., 20 MHz span for LTE channel)
   - Set resolution bandwidth (RBW) appropriately - narrower RBW for detailed resolution, wider for faster sweeps

2. **Initial Survey**
   - Perform a full frequency sweep across the band to identify signal presence
   - Note the power levels of expected signals vs. unexpected signals
   - Identify anomalies: spurs, harmonics, or out-of-band emissions

3. **Identify Interference Sources**
   - **Co-channel interference**: Signals at the same frequency with unexpected source
   - **Adjacent channel interference**: Signals in neighboring channels leaking in
   - **Out-of-band interference**: Signals outside the operating band (harmonics, intermodulation products)
   - **Broadband noise**: Elevated noise floor indicating potential interference

4. **Detailed Analysis**
   - Zoom into suspicious signals
   - Use marker functions to measure exact frequency, amplitude, and bandwidth
   - Measure occupied bandwidth to identify if signal violates spectral masks
   - Use peak search to identify the strongest interference source

5. **Mitigation Steps**
   - If fixed interference (e.g., WiFi in 2.4 GHz), test device's interference mitigation capabilities
   - Measure device's ability to maintain performance despite interference
   - Document frequency, power level, and modulation type of interferer

### Example Scenario:
A device shows degraded LTE performance. Using spectrum analyzer:
- Center at 2.145 GHz (LTE Band 7 downlink)
- Discover WiFi channel 6 (2.437 GHz) leaking -40 dBm into the LTE band
- Confirm device meets interference rejection specifications
- Root cause: Insufficient RF shielding or filter performance

---

## 19. Network Emulator: Testing Handover Scenarios

### Network Emulator Setup for Handover Testing:

1. **Equipment Connection**
   - Connect device under test to network emulator's RF interface
   - Emulator simulates two or more eNodeBs in controlled environment
   - Configure emulator to control channel conditions, power, and RRC messages

2. **Simulating Handover Conditions**
   - **Source Cell**: Configure eNodeB A with strong signal (-70 dBm)
   - **Target Cell**: Configure eNodeB B with weaker signal (-100 dBm initially)
   - **Handover Trigger**: As device moves (simulated), gradually increase eNodeB B power while decreasing eNodeB A power

3. **Handover Scenarios to Test**

   a) **Intra-eNodeB Handover**
   - Movement between sectors of same eNodeB
   - Measure handover latency
   - Verify no call drops or packet loss

   b) **Inter-eNodeB Handover**
   - Handover between different eNodeBs
   - Test X2 interface communication
   - Measure preparation time, execution time, and completion time

   c) **Hard Handover**
   - Source cell immediately releases resources
   - Measure service interruption time (typically <150 ms for LTE)
   - Verify no data loss

   d) **Soft Handover Preparation**
   - Measure measurement gaps configured by network
   - Verify device synchronizes to target cell measurements
   - Confirm HO report timing

4. **Measurements**
   - Handover success rate (target: >99%)
   - Service interruption time
   - Packet loss during HO
   - RRC connection establishment time
   - CSFB (Circuit Switched FallBack) latency if applicable

5. **Failure Scenarios**
   - Test HO failure recovery (device returns to source cell)
   - Test connection re-establishment after failed HO
   - Verify user experience during failure (call drop, data interruption)

### Example Scenario:
Testing 5G handover from LTE to 5G NR:
- eNodeB (LTE) at -70 dBm
- gNodeB (5G) at -100 dBm, gradually increase to -60 dBm
- Measure 4G-to-5G handover latency
- Verify no video call interruption
- Confirm data throughput increases post-handover

---

## 20. Signal Generator: Multi-Carrier Signal Testing

### Generating Multi-Carrier Signals for Receiver Testing:

1. **Signal Generator Configuration**
   - Use arbitrary waveform generator (AWG) or advanced signal generator
   - Load pre-generated waveforms: LTE, 5G NR, or custom standards

2. **LTE Multi-Carrier Generation**
   - **Carrier Aggregation (CA)**: Generate multiple LTE carriers simultaneously
   - Example: LTE Band 7 (primary) + Band 3 (secondary) in dual-carrier setup
   - Each carrier: 20 MHz bandwidth, OFDM modulation (QPSK, 16-QAM, 64-QAM)
   - Power control: Configure each carrier power independently

3. **5G NR Multi-Carrier Setup**
   - Generate multiple NR carriers with different numerologies
   - Subcarrier spacing: 15 kHz, 30 kHz, 60 kHz, 120 kHz
   - Test device's ability to decode multiple numerologies simultaneously

4. **Testing Receiver Performance**

   a) **Sensitivity Testing**
   - Gradually reduce signal power from -50 dBm to -130 dBm
   - Measure Block Error Rate (BLER) at each power level
   - Target: 10% BLER at specified sensitivity level (e.g., -104 dBm for LTE)

   b) **Multi-Carrier Interference**
   - Generate primary carrier at nominal power (-50 dBm)
   - Add interfering carrier at adjacent frequency with varying power
   - Measure device's SINR (Signal-to-Interference-plus-Noise Ratio) requirements
   - Verify Adjacent Channel Leakage Ratio (ACLR) compliance

   c) **Modulation Quality Testing**
   - Generate high-order modulation signals (64-QAM, 256-QAM)
   - Measure EVM (Error Vector Magnitude) at receiver output
   - Verify device decodes complex modulation accurately

5. **Channel Emulation**
   - Add fading profiles: Rayleigh, Rician, EPA (Extended Pedestrian A), EVA (Extended Vehicular A)
   - Simulate Doppler effects for mobile scenarios
   - Test device's channel estimation and equalization algorithms

### Example Scenario:
Testing dual-carrier LTE device:
- Generate LTE Band 7 primary carrier (2.145 GHz) at -70 dBm
- Generate LTE Band 3 secondary carrier (1.805 GHz) at -75 dBm
- Add AWGN (Additive White Gaussian Noise) to simulate realistic conditions
- Measure device's aggregated throughput
- Verify device switches to single carrier if secondary carrier power drops below threshold

---

## 21. Vector Signal Analyzer (VSA): Measurements and Analysis

### VSA Capabilities and Measurements:

1. **Signal Capture and Demodulation**
   - Capture RF signal (e.g., LTE waveform) in real-time
   - Demodulate complex signals: OFDM, QAM, PSK, FSK
   - Digitize signal for detailed analysis
   - Time synchronization and frame boundary detection

2. **Key Measurements**

   a) **Modulation Quality**
   - **EVM (Error Vector Magnitude)**: Measure modulation accuracy
     - EVM % = (RMS error vector / RMS reference vector) × 100
     - Target for LTE: <8% for 64-QAM, <3% for QPSK
   - **Constellation Diagram**: Visual display of transmitted symbols vs. ideal positions
   - **Phase/Magnitude Error**: Individual tracking of phase and amplitude distortions

   b) **Spectral Measurements**
   - **Occupied Bandwidth**: Measure signal bandwidth containing 99% of power
   - **Power Spectral Density (PSD)**: Power distribution across frequency
   - **Spectral Flatness**: Variation in power across subcarriers (OFDM)
   - **In-Band Ripple**: Unwanted variations in transmit power spectrum

   c) **Power Measurements**
   - **Average Power**: Mean transmit power over measurement interval
   - **Peak Power**: Maximum instantaneous power
   - **Peak-to-Average Power Ratio (PAPR)**: Important for efficiency assessment
   - **Power Ramp Time**: Time to reach steady-state power

   d) **Timing Measurements**
   - **Symbol Timing Error**: Deviation from ideal symbol clock
   - **Frame Synchronization**: Detect frame boundaries, measure synchronization quality
   - **Carrier Frequency Offset (CFO)**: Deviation from expected carrier frequency
   - **Sampling Clock Error**: Timing accuracy of sample clock

3. **Protocol-Specific Analysis**

   a) **LTE Analysis**
   - Decode Resource Blocks (RBs), subcarriers, OFDM symbols
   - Extract Physical Downlink Shared Channel (PDSCH) data
   - Measure PDCCH (Physical Downlink Control Channel) integrity
   - Analyze pilot (Reference Signal) quality

   b) **5G NR Analysis**
   - Support multiple numerologies (15 kHz to 240 kHz)
   - Decode PDSCH, PUSCH, PDCCH across wideband spectrum
   - Measure beam characteristics (millimeter wave specific)
   - Analyze SISO vs. MIMO performance

4. **Troubleshooting and Debugging**
   - Identify modulation issues: IQ imbalance, phase noise
   - Detect transmitter impairments: Non-linearity, AM/PM conversion
   - Measure receiver performance: SNR, SINR at demodulation
   - Validate compliance with 3GPP standards

### Example Scenario:
Testing LTE device transmission quality:
- Capture device's LTE uplink signal with VSA
- Measure EVM: 4.5% (well below 8% spec)
- Analyze constellation: Good symbol clustering, minimal scatter
- Check spectral mask: In-band flatness within ±3 dB
- Confirm frequency accuracy: ±10 Hz (spec: ±100 Hz)
- Result: Device meets transmission quality requirements

---

## 22. Protocol Tester: Validating RRC Messages

### Protocol Tester Setup for RRC Validation:

1. **Equipment Configuration**
   - Protocol tester acts as eNodeB, running full 3GPP protocol stack
   - Connected to device under test via RF interface or wired connection
   - Configured to simulate cellular network base station behavior

2. **RRC Connection Establishment Testing**

   a) **Cell Search and Synchronization**
   - Device finds cell (PBCH broadcast)
   - Verify MasterInformationBlock (MIB) decoding
   - Verify SystemInformationBlockType1 (SIB1) reception

   b) **Initial Connection**
   - Measure RRCConnectionRequest timing
   - Verify correct UE Category/Capabilities reported
   - Validate RRCConnectionSetup message acceptance
   - Confirm RRCConnectionSetupComplete transmission

   c) **Measurements and Reporting**
   - Verify device performs configured measurements
   - Test measurement configuration from RRCConnectionReconfiguration
   - Validate MeasurementReport message format and periodicity
   - Check correctness of RSRP/RSRQ measurements

3. **Configuration Message Validation**

   a) **RadioResourceConfiguration**
   - DRB (Data Radio Bearer) setup and modification
   - Logical channel configuration
   - MAC/PHY parameter configuration (TBS, MCS, HARQ settings)

   b) **Handover Preparation**
   - Verify HO preparation message correctly triggers handover
   - Check RRCConnectionReconfiguration for handover command
   - Validate correct target cell parameters applied
   - Measure HO completion time

   c) **RLC/PDCP Configuration**
   - Test SRB (Signaling Radio Bearer) and DRB parameters
   - Verify reordering buffer behavior
   - Test PDCP integrity protection and ciphering activation
   - Validate status reports (RLC ACKs)

4. **Message Sequence and Timing Tests**

   a) **Attach Procedure (LTE)**
   - Device: RRCConnectionRequest → Network: RRCConnectionSetup
   - Device: RRCConnectionSetupComplete with NAS message
   - Network: RRCConnectionReconfiguration (if needed)
   - Verify end-to-end timing

   b) **Detach Procedure**
   - Network sends RRCConnectionRelease
   - Device: RRCConnectionReleaseComplete
   - Verify clean resource cleanup

   c) **Service Request**
   - Device initiates data transfer
   - Network allocates PDCP/RLC/MAC resources
   - Verify rapid transition to data ready state

5. **Error Scenarios and Recovery**

   a) **RRC Message Errors**
   - Send malformed RRC messages
   - Device should maintain RRC connection (graceful handling)
   - Verify correct error reporting

   b) **Contention Resolution**
   - Multiple devices in random access
   - Verify device correctly resolves contention
   - Measure success rate of random access procedure

   c) **Connection Loss Recovery**
   - Intentionally drop RRC connection
   - Device should perform RRCConnectionReestablishment
   - Verify PDCP data buffer handling

6. **Compliance Testing**
   - Validate against 3GPP TS 36.508 (RRC protocol definitions)
   - Test state machine transitions (RRC_IDLE → RRC_CONNECTED → RRC_IDLE)
   - Verify timer expirations and recovery procedures
   - Ensure asynchronous message handling

### Example Scenario:
Testing LTE device RRC behavior:
- Protocol tester broadcasts cell with specific SIBs
- Device performs cell selection and sends RRCConnectionRequest
- Tester responds with RRCConnectionSetup containing:
  - SRB1 configuration
  - Measurement configuration
  - Security algorithms (encryption, integrity)
- Device transitions to RRC_CONNECTED
- Tester sends RRCConnectionReconfiguration to add DRB1
- Device confirms with RRCConnectionReconfigurationComplete
- Verify: All messages correctly formatted, timing within spec, state transitions correct
- Result: Device RRC implementation compliant with 3GPP standards

---

## Summary Table: Equipment Use Cases

| Equipment | Primary Use | Key Metrics | Common Pitfalls |
|-----------|------------|-------------|-----------------|
| **Spectrum Analyzer** | Interference identification, emissions compliance | Power, frequency, bandwidth | Incorrect RBW setting, antenna coupling |
| **Network Emulator** | Handover, mobility, scenario testing | HO latency, success rate, BLER | Insufficient eNodeB separation simulation |
| **Signal Generator** | Receiver testing, sensitivity measurements | EVM, throughput, BLER | Incorrect modulation profile, power calibration |
| **VSA** | Transmitter quality, demodulation analysis | EVM, PAPR, spectral mask | Timing synchronization, inadequate capture time |
| **Protocol Tester** | RRC validation, 3GPP compliance | Message correctness, timing, state transitions | Insufficient error case coverage, timing tolerance |
