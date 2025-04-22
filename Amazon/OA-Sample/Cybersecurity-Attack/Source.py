def findMinimumTime(password: str, attackOrder: list[int], m: int) -> int:
    """
    Calculates the minimum time after which a password becomes irrecoverable
    given a specific attack order.

    Args:
        password: The initial password string.
        attackOrder: An array representing the order in which characters in the
            password are attacked (replaced with '*').  The values are 1-indexed.
        m: The recoverability parameter. The password is irrecoverable when the
            number of substrings containing at least one '*' is >= m.

    Returns:
        The minimum time (number of attacks) after which the password becomes
        irrecoverable.
    """
    n = len(password)
    password_list = list(password)  # Convert string to list for mutability
    time = 0

    def count_infected_substrings(current_password: list[str]) -> int:
        """
        Counts the number of substrings in the current password that contain
        at least one '*'.

        Args:
            current_password: The current state of the password as a list of characters.

        Returns:
            The number of infected substrings.
        """
        count = 0
        for i in range(len(current_password)):
            for j in range(i, len(current_password)):
                substring = current_password[i : j + 1]
                if any(char == '*' for char in substring):
                    count += 1
        return count

    for attacked_index in attackOrder:
        time += 1
        # Convert the 1-indexed attackOrder to 0-indexed for list access.
        attack_index_0_based = attacked_index - 1
        password_list[attack_index_0_based] = '*'  # Infect the character

        infected_substring_count = count_infected_substrings(password_list)
        if infected_substring_count >= m:
            return time

    return n  # If the loop finishes without reaching m, return n.  This isn't in the original problem description, but is added for completeness.

def test_findMinimumTime():
    """
    Tests the findMinimumTime function with the provided examples and additional
    test cases.
    """
    # Test Case 1
    password = "abc"
    attackOrder = [1, 2, 3]
    m = 1
    expected_output = 1
    actual_output = findMinimumTime(password, attackOrder, m)
    print(f"Test Case 1: Password: {password}, Attack Order: {attackOrder}, m: {m}")
    print(f"Expected Output: {expected_output}, Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test Case 1 Failed: Expected {expected_output}, got {actual_output}"

    # Test Case 2
    password = "bcdb"
    attackOrder = [2, 4, 1, 3]
    m = 10
    expected_output = 4
    actual_output = findMinimumTime(password, attackOrder, m)
    print(f"Test Case 2: Password: {password}, Attack Order: {attackOrder}, m: {m}")
    print(f"Expected Output: {expected_output}, Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test Case 2 Failed: Expected {expected_output}, got {actual_output}"

    # Test Case 3:  m is larger than the number of possible infected substrings.
    password = "abcde"
    attackOrder = [1, 2, 3, 4, 5]
    m = 16  # There are 15 possible infected substrings with 5 characters: 5 + 4 + 3 + 2 + 1
    expected_output = 5 # Should return the length of the string
    actual_output = findMinimumTime(password, attackOrder, m)
    print(f"Test Case 3: Password: {password}, Attack Order: {attackOrder}, m: {m}")
    print(f"Expected Output: {expected_output}, Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test Case 3 Failed: Expected {expected_output}, got {actual_output}"

    # Test Case 4:  Early infection
    password = "aaaa"
    attackOrder = [1, 2, 3, 4]
    m = 1
    expected_output = 1
    actual_output = findMinimumTime(password, attackOrder, m)
    print(f"Test Case 4: Password: {password}, Attack Order: {attackOrder}, m: {m}")
    print(f"Expected Output: {expected_output}, Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test Case 4 Failed: Expected {expected_output}, got {actual_output}"

    # Test Case 5:  Attack order that infects from the end
    password = "abcdef"
    attackOrder = [6, 5, 4, 3, 2, 1]
    m = 5
    expected_output = 3
    actual_output = findMinimumTime(password, attackOrder, m)
    print(f"Test Case 5: Password: {password}, Attack Order: {attackOrder}, m: {m}")
    print(f"Expected Output: {expected_output}, Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test Case 5 Failed: Expected {expected_output}, got {actual_output}"
    print("All test cases passed!")

if __name__ == "__main__":
    test_findMinimumTime()
