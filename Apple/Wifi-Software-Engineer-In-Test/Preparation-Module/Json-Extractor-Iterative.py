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

def get_keys_iteratively(data, target_key):
    """
    Iteratively searches for all values matching a specific key in a nested JSON structure.
    Uses a stack-based approach to traverse the nested structure without recursion.
    Uses isinstance() for type checking.
    
    Args:
        data (dict | list): The JSON data to search.
        target_key (str): The key to find.
        
    Returns:
        list: A list of values associated with the target_key.
    """
    found_values = []
    stack = [data]  # Initialize stack with the root data
    
    while stack:
        current = stack.pop()  # Pop the most recent item from stack
        
        if isinstance(current, dict):
            for key, value in current.items():
                if key == target_key:
                    found_values.append(value)
                # Push nested dicts or lists to stack for further processing
                if isinstance(value, (dict, list)):
                    stack.append(value)
                    
        elif isinstance(current, list):
            for item in current:
                stack.append(item)
                
    return found_values

def get_keys_iteratively_with_type(data, target_key):
    """
    Iteratively searches for all values matching a specific key in a nested JSON structure.
    Uses a stack-based approach to traverse the nested structure without recursion.
    Uses type() for type checking instead of isinstance().
    
    Args:
        data (dict | list): The JSON data to search.
        target_key (str): The key to find.
        
    Returns:
        list: A list of values associated with the target_key.
    """
    found_values = []
    stack = [data]  # Initialize stack with the root data
    
    while stack:
        current = stack.pop()  # Pop the most recent item from stack
        
        if type(current) == dict:
            for key, value in current.items():
                if key == target_key:
                    found_values.append(value)
                # Push nested dicts or lists to stack for further processing
                if type(value) == dict or type(value) == list:
                    stack.append(value)
                    
        elif type(current) == list:
            for item in current:
                stack.append(item)
                
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
        
        # Extract all occurrences of a key using isinstance()
        all_ids = get_keys_iteratively(loaded_data, "config_id")
        print(f"All 'config_id' values found (using isinstance): {all_ids}")
        
        # Extract all occurrences of a key using type()
        all_ids_type = get_keys_iteratively_with_type(loaded_data, "config_id")
        print(f"All 'config_id' values found (using type): {all_ids_type}")

    # Cleanup
    if os.path.exists(dummy_path):
        os.remove(dummy_path)
