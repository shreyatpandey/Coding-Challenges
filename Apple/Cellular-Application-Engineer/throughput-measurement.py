def throughput_measurement(no_of_bits, time_in_seconds, retransmissions=0):
    """
    Calculate throughput (actual data transmitted including retransmissions).
    
    In cellular networks, throughput includes ALL transmitted data, 
    including retransmitted packets. This is the raw channel throughput.
    
    Args:
        no_of_bits (int): Original number of bits transmitted (positive int)
        time_in_seconds (float): Time duration for measurement (positive float)
        retransmissions (int): Number of retransmitted packets (non-negative int)
    
    Returns:
        float: Throughput in bits per second (bps)
    
    Raises:
        ValueError: If inputs are invalid
        ZeroDivisionError: If time_in_seconds is zero
    
    Example:
        >>> throughput_measurement(1000000, 10, 0)  # 1M bits in 10 sec, no retransmissions
        100000.0
        
        >>> throughput_measurement(1000000, 10, 2)  # With 2 retransmissions
        300000.0
    """
    # Input validation
    if not isinstance(no_of_bits, (int, float)) or no_of_bits < 0:
        raise ValueError(f"no_of_bits must be non-negative number, got {no_of_bits}")
    
    if not isinstance(time_in_seconds, (int, float)) or time_in_seconds < 0:
        raise ValueError(f"time_in_seconds must be non-negative number, got {time_in_seconds}")
    
    if not isinstance(retransmissions, int) or retransmissions < 0:
        raise ValueError(f"retransmissions must be non-negative integer, got {retransmissions}")
    
    # Handle edge case: zero time
    if time_in_seconds == 0:
        raise ZeroDivisionError("time_in_seconds cannot be zero")
    
    # Calculate total bits transmitted (original + all retransmissions)
    total_bits_transmitted = no_of_bits * (1 + retransmissions)
    
    # Throughput = Total bits / Time (in bits per second)
    throughput_bps = total_bits_transmitted / time_in_seconds
    
    return throughput_bps


def goodput_measurement(no_of_bits, time_in_seconds, retransmissions=0):
    """
    Calculate goodput (usable data successfully delivered).
    
    Goodput is the actual useful data rate - it excludes retransmitted 
    packets and only counts successfully delivered data.
    
    Args:
        no_of_bits (int): Number of unique bits successfully delivered
        time_in_seconds (float): Total measurement time
        retransmissions (int): Number of retransmitted packets
    
    Returns:
        float: Goodput in bits per second (bps)
    
    Example:
        >>> goodput_measurement(1000000, 10, 2)  # 1M bits delivered in 10 sec
        100000.0  # Goodput is same as original, retransmissions don't count
    """
    if not isinstance(no_of_bits, (int, float)) or no_of_bits < 0:
        raise ValueError(f"no_of_bits must be non-negative number, got {no_of_bits}")
    
    if not isinstance(time_in_seconds, (int, float)) or time_in_seconds < 0:
        raise ValueError(f"time_in_seconds must be non-negative number, got {time_in_seconds}")
    
    if time_in_seconds == 0:
        raise ZeroDivisionError("time_in_seconds cannot be zero")
    
    # Goodput = Only successful bits / Time (retransmissions don't count)
    goodput_bps = no_of_bits / time_in_seconds
    
    return goodput_bps


def calculate_retransmission_rate(retransmissions, total_packets):
    """
    Calculate retransmission rate percentage.
    
    Args:
        retransmissions (int): Number of retransmitted packets
        total_packets (int): Total packets transmitted (original + retransmissions)
    
    Returns:
        float: Retransmission rate as percentage
    
    Example:
        >>> calculate_retransmission_rate(2, 5)  # 2 retrans out of 5 total
        40.0  # 40% of transmissions were retransmissions
    """
    if total_packets == 0:
        raise ZeroDivisionError("total_packets cannot be zero")
    
    return (retransmissions / total_packets) * 100


def analyze_throughput_vs_goodput(no_of_bits, time_in_seconds, retransmissions):
    """
    Compare throughput and goodput to understand channel efficiency.
    
    Returns:
        dict: Comprehensive throughput analysis
    """
    try:
        throughput = throughput_measurement(no_of_bits, time_in_seconds, retransmissions)
        goodput = goodput_measurement(no_of_bits, time_in_seconds, retransmissions)
        
        # Channel efficiency = goodput / throughput
        if throughput > 0:
            efficiency = (goodput / throughput) * 100
        else:
            efficiency = 0
        
        total_transmissions = 1 + retransmissions
        retrans_rate = calculate_retransmission_rate(retransmissions, total_transmissions)
        
        return {
            'throughput_bps': throughput,
            'goodput_bps': goodput,
            'channel_efficiency_percent': efficiency,
            'retransmission_rate_percent': retrans_rate,
            'total_packets_sent': total_transmissions
        }
    except (ValueError, ZeroDivisionError) as e:
        return {'error': str(e)}


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("THROUGHPUT MEASUREMENT EXAMPLES")
    print("=" * 60)
    
    # Test Case 1: No retransmissions (ideal case)
    print("\n--- Test Case 1: Ideal Scenario (No Retransmissions) ---")
    bits = 1_000_000  # 1 Mbits
    time = 10         # 10 seconds
    retrans = 0
    
    try:
        throughput = throughput_measurement(bits, time, retrans)
        print(f"Bits: {bits:,}, Time: {time}s, Retransmissions: {retrans}")
        print(f"Throughput: {throughput:,.0f} bps = {throughput/1_000_000:.2f} Mbps")
    except Exception as e:
        print(f"Error: {e}")
    
    # Test Case 2: With retransmissions (real-world scenario)
    print("\n--- Test Case 2: Real-World Scenario (With Retransmissions) ---")
    retrans = 2
    try:
        result = analyze_throughput_vs_goodput(bits, time, retrans)
        print(f"Bits: {bits:,}, Time: {time}s, Retransmissions: {retrans}")
        print(f"Throughput: {result['throughput_bps']:,.0f} bps = {result['throughput_bps']/1_000_000:.2f} Mbps")
        print(f"Goodput:    {result['goodput_bps']:,.0f} bps = {result['goodput_bps']/1_000_000:.2f} Mbps")
        print(f"Channel Efficiency: {result['channel_efficiency_percent']:.1f}%")
        print(f"Retransmission Rate: {result['retransmission_rate_percent']:.1f}%")
    except Exception as e:
        print(f"Error: {e}")
    
    # Test Case 3: High retransmission rate (poor channel)
    print("\n--- Test Case 3: Poor Channel (High Retransmissions) ---")
    bits = 1_000_000
    time = 10
    retrans = 5  # Heavy retransmissions
    
    try:
        result = analyze_throughput_vs_goodput(bits, time, retrans)
        print(f"Bits: {bits:,}, Time: {time}s, Retransmissions: {retrans}")
        print(f"Throughput: {result['throughput_bps']:,.0f} bps = {result['throughput_bps']/1_000_000:.2f} Mbps")
        print(f"Goodput:    {result['goodput_bps']:,.0f} bps = {result['goodput_bps']/1_000_000:.2f} Mbps")
        print(f"Channel Efficiency: {result['channel_efficiency_percent']:.1f}%")
        print(f"Retransmission Rate: {result['retransmission_rate_percent']:.1f}%")
    except Exception as e:
        print(f"Error: {e}")
    
    # Test Case 4: Error handling - invalid input
    print("\n--- Test Case 4: Error Handling ---")
    try:
        throughput_measurement(-1000, 10, 0)  # Negative bits
    except ValueError as e:
        print(f"✓ Caught expected error: {e}")
    
    try:
        throughput_measurement(1000, 0, 0)  # Zero time
    except ZeroDivisionError as e:
        print(f"✓ Caught expected error: {e}")
    
    try:
        throughput_measurement(1000, 10, -1)  # Negative retransmissions
    except ValueError as e:
        print(f"✓ Caught expected error: {e}")
    
    print("\n" + "=" * 60)