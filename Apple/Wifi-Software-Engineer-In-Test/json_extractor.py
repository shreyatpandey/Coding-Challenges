import json
import os

def extract_from_json(file_path):
    """
    Reads a JSON file and returns its content as a Python dictionary or list.
    
    Args:
        file_path (str): The path to the JSON file.
        
    Returns:
        dict/list: The parsed JSON data.
        None: If the file is not found or invalid.
    """
    try:
        with open(file_path, 'r') as f:
            data = json.load(f)
            return data
    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
        return None
    except json.JSONDecodeError:
        print(f"Error: The file '{file_path}' contains invalid JSON.")
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

def get_keys_recursively(data, target_key, found_values=None):
    """
    Recursively searches for all values matching a specific key in a nested JSON structure.
    
    Args:
        data (dict | list): The JSON data to search.
        target_key (str): The key to find.
        found_values (list): Accumulator for found values.
        
    Returns:
        list: A list of values associated with the target_key.
    """
    if found_values is None:
        found_values = []

    if isinstance(data, dict):
        for key, value in data.items():
            if key == target_key:
                found_values.append(value)
            # Recursive call for nested dicts or lists
            if isinstance(value, (dict, list)):
                get_keys_recursively(value, target_key, found_values)
                
    elif isinstance(data, list):
        for item in data:
            get_keys_recursively(item, target_key, found_values)
            
    return found_values

if __name__ == "__main__":
    # Example Usage
    
    # 1. basic usage
    # data = extract_from_json('path/to/your/file.json')
    
    # 2. Demo with a temporary file
    dummy_path = "demo_config.json"
    sample_data = {
        "config_id": "conf_001",
        "nested": {
            "config_id": "conf_nested",
            "details": "example"
        },
        "items": [
            {"name": "item1", "config_id": "conf_arr_1"},
            {"name": "item2"}
        ]
    }
    
    with open(dummy_path, 'w') as f:
        json.dump(sample_data, f, indent=2)
        
    print(f"--- parsing {dummy_path} ---")
    loaded_data = extract_from_json(dummy_path)
    
    if loaded_data:
        # Extract a specific top-level field
        print(f"Top Level ID: {loaded_data.get('config_id')}")
        
        # Extract all occurrences of a key recursively
        all_ids = get_keys_recursively(loaded_data, "config_id")
        print(f"All 'config_id' values found: {all_ids}")

    # Cleanup
    if os.path.exists(dummy_path):
        os.remove(dummy_path)
