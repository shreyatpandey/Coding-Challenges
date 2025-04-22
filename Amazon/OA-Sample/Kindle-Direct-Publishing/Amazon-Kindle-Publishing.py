def getBalancedSplits(s):
    """
    Determines the number of ways a string consisting of '(', ')', '[', ']',
    and '?' can be split into two non-empty substrings, such that each
    substring can be rearranged into a balanced bracket string.

    A substring can be rearranged into a balanced string if and only if:
    1. Its length is even.
    2. The sum of the absolute differences between the counts of open and close
       round brackets, and open and close square brackets, is less than or
       equal to the count of question marks.

    Args:
        s: The input string.

    Returns:
        The number of valid split points.
    """
    n = len(s)

    # If the total length of the string is odd, it's impossible to split it
    # into two substrings of even length.
    if n % 2 != 0:
        return 0

    # Precompute prefix counts for each character type.
    # prefix_counts[k] will store the counts for the substring s[:k].
    prefix_open_round = [0] * (n + 1)
    prefix_close_round = [0] * (n + 1)
    prefix_open_square = [0] * (n + 1)
    prefix_close_square = [0] * (n + 1)
    prefix_q_marks = [0] * (n + 1)

    for i in range(n):
        prefix_open_round[i + 1] = prefix_open_round[i]
        prefix_close_round[i + 1] = prefix_close_round[i]
        prefix_open_square[i + 1] = prefix_open_square[i]
        prefix_close_square[i + 1] = prefix_close_square[i]
        prefix_q_marks[i + 1] = prefix_q_marks[i]

        if s[i] == '(':
            prefix_open_round[i + 1] += 1
        elif s[i] == ')':
            prefix_close_round[i + 1] += 1
        elif s[i] == '[':
            prefix_open_square[i + 1] += 1
        elif s[i] == ']':
            prefix_close_square[i + 1] += 1
        elif s[i] == '?':
            prefix_q_marks[i + 1] += 1

    # Total counts for the entire string s
    total_or = prefix_open_round[n]
    total_cr = prefix_close_round[n]
    total_os = prefix_open_square[n]
    total_cs = prefix_close_square[n]
    total_q = prefix_q_marks[n]

    count = 0

    # Iterate through possible split points i.
    # A split at index i divides the string into s[:i] and s[i:].
    # Both substrings must be non-empty, so 1 <= i <= n-1.
    # Both substrings must have even length. Since the total length n is even,
    # if the first substring s[:i] has even length i, the second substring
    # s[i:] will also have even length (n - i).
    # So, we only need to consider even values of i from 2 to n-2.
    for i in range(2, n, 2):
        # Counts for the first substring s1 = s[:i]
        or1 = prefix_open_round[i]
        cr1 = prefix_close_round[i]
        os1 = prefix_open_square[i]
        cs1 = prefix_close_square[i]
        q1 = prefix_q_marks[i]
        len1 = i

        # Counts for the second substring s2 = s[i:]
        or2 = total_or - or1
        cr2 = total_cr - cr1
        os2 = total_os - os1
        cs2 = total_cs - cs1
        q2 = total_q - q1
        len2 = n - i

        # Check if the first substring s1 can be rearranged into a balanced string
        is_s1_balanceable = (len1 % 2 == 0) and (abs(cr1 - or1) + abs(cs1 - os1) <= q1)

        # Check if the second substring s2 can be rearranged into a balanced string
        is_s2_balanceable = (len2 % 2 == 0) and (abs(cr2 - or2) + abs(cs2 - os2) <= q2)

        # If both substrings are balanceable, increment the count of valid splits
        if is_s1_balanceable and is_s2_balanceable:
            count += 1

    return count

# Test Cases
test_cases = [
    ('(?][', 1),  # Example 1
    ('????', 1),
    ('()[]', 1),
    (')(][', 1),
    ('()()', 1),
    ('((()))', 0),
    ('[[()]]', 0),
    ('()[]?(', 0), # Odd length
    ('()[]??', 2),
    ('????????', 3),
    ('[]', 0), # Length 2, no split possible into two non-empty substrings
    ('(())', 0),
    ('??', 0), # Length 2, no split possible into two non-empty substrings
    ('(?])', 0), # Length 4, i=2. s1='(?', s2='])'.
                 # s1: or=1, q=1, len=2. abs(0-1)+abs(0-0)=1. q=1. 1<=1 T.
                 # s2: cr=1, cs=1, len=2. abs(1-0)+abs(1-0)=2. q=0. 2<=0 F.
]

# Run the test cases
for s, expected_output in test_cases:
    actual_output = getBalancedSplits(s)
    print(f"Input String: \"{s}\"")
    print(f"Expected Output: {expected_output}")
    print(f"Actual Output: {actual_output}")
    assert actual_output == expected_output, f"Test failed for input \"{s}\". Expected {expected_output}, got {actual_output}"
    print("-" * 30)
