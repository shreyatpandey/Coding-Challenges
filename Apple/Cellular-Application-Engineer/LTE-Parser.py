def parse_lte_report(input_string):
    """
    Parse LTE measurement report string and return a dictionary.
    
    Args:
        input_string: Comma-separated measurement pairs (e.g., "RSRP: -95 dBm, RSRQ: -10 dB")
    
    Returns:
        dict: Dictionary with measurement names as keys and values (with units)
        
    Raises:
        ValueError: If input format is invalid
    
    Example:
        >>> result = parse_lte_report("RSRP: -95 dBm, RSRQ: -10 dB")
        >>> print(result['RSRP'])
        -95 dBm
    """
    if not input_string or not isinstance(input_string, str):
        raise ValueError("Input must be a non-empty string")
    
    lte_dict = {}
    measurements = input_string.split(',')
    
    for measurement in measurements:
        measurement = measurement.strip()
        if not measurement:  # Skip empty entries
            continue
            
        if ':' not in measurement:
            raise ValueError(f"Invalid measurement format: '{measurement}'. Expected 'key: value'")
        
        try:
            key, value = measurement.split(':', 1)  # Use maxsplit=1 to handle values with colons
            key = key.strip()
            value = value.strip()
            
            if not key or not value:
                raise ValueError(f"Empty key or value in: '{measurement}'")
            
            lte_dict[key] = value
            
        except ValueError as e:
            raise ValueError(f"Failed to parse measurement '{measurement}': {str(e)}")
    
    if not lte_dict:
        raise ValueError("No valid measurements found in input string")
    
    return lte_dict


def parse_lte_report_with_validation(input_string):
    """
    Parse LTE measurement report with numeric validation.
    Separates measurement name from unit and validates ranges.
    
    Args:
        input_string: Comma-separated measurement pairs
    
    Returns:
        dict: {measurement_name: {value: float, unit: str}}
    """
    measurements = parse_lte_report(input_string)
    validated_dict = {}
    
    # Expected ranges for common LTE measurements
    valid_ranges = {
        'RSRP': (-140, -44),      # dBm
        'RSRQ': (-19.5, -3),      # dB
        'SINR': (-20, 30),        # dB
        'CQI': (0, 15),           # Index
        'PCI': (0, 503),          # Physical Cell ID
    }
    
    for key, value_with_unit in measurements.items():
        parts = value_with_unit.rsplit(' ', 1)
        
        if len(parts) == 2:
            value_str, unit = parts
        else:
            value_str = parts[0]
            unit = ''
        
        try:
            numeric_value = float(value_str)
            
            # Validate range if known
            if key in valid_ranges:
                min_val, max_val = valid_ranges[key]
                if not (min_val <= numeric_value <= max_val):
                    print(f"Warning: {key} value {numeric_value} {unit} is outside expected range ({min_val}, {max_val})")
            
            validated_dict[key] = {
                'value': numeric_value,
                'unit': unit,
                'raw': value_with_unit
            }
        except ValueError:
            print(f"Warning: Could not convert {key} value '{value_str}' to number")
            validated_dict[key] = {
                'value': None,
                'unit': unit,
                'raw': value_with_unit
            }
    
    return validated_dict


if __name__ == "__main__":
    # Test Case 1: Normal input
    print("=== Test Case 1: Normal Input ===")
    input_string = "RSRP: -95 dBm, RSRQ: -10 dB, SINR: 20 dB"
    result = parse_lte_report(input_string)
    print(f"Parsed: {result}")
    print()
    
    # Test Case 2: Validation with numeric values
    print("=== Test Case 2: With Validation ===")
    result_validated = parse_lte_report_with_validation(input_string)
    for key, data in result_validated.items():
        print(f"{key}: {data['value']} {data['unit']}")
    print()
    
    # Test Case 3: Edge case - multiple spaces
    print("=== Test Case 3: Multiple Spaces ===")
    input_string2 = "RSRP:  -105 dBm  ,  RSRQ:  -15 dB  "
    result2 = parse_lte_report(input_string2)
    print(f"Parsed: {result2}")
    print()
    
    # Test Case 4: Error handling
    print("=== Test Case 4: Error Handling ===")
    try:
        bad_input = "RSRP -95 dBm, RSRQ: -10 dB"  # Missing colon
        parse_lte_report(bad_input)
    except ValueError as e:
        print(f"Caught error: {e}")
    print()
    
    # Test Case 5: Out of range warning
    print("=== Test Case 5: Out of Range Warning ===")
    input_string3 = "RSRP: -40 dBm, SINR: 50 dB"  # RSRP too high, SINR too high
    result3 = parse_lte_report_with_validation(input_string3)