def getMaxStabilityGreedy(reliability, availability):
    """
    Calculates the maximum possible stability of any subset of servers 
    using a greedy approach.

    Args:
        reliability: List of integer reliability factors for each server.
        availability: List of integer availability factors for each server.

    Returns:
        The maximum stability modulo (10^9 + 7).
    """

    n = len(reliability)
    mod = 10**9 + 7

    # Sort servers by availability in descending order
    sorted_indices = sorted(range(n), key=lambda x: availability[x], reverse=True)

    # Calculate cumulative sum of reliabilities in sorted order
    sorted_reliability = [reliability[i] for i in sorted_indices]
    reliability_sum = [r for r in sorted_reliability]
    for i in range(1, n):
        reliability_sum[i] += reliability_sum[i - 1]

    # Calculate maximum stability
    max_stability = 0
    for i in range(n):
        stability = availability[sorted_indices[i]] * reliability_sum[i]
        max_stability = max(max_stability, stability)

    return max_stability % mod

# Example usage
if __name__ == "__main__":
    reliability = [1, 2, 2]
    availability = [1, 1, 3]
    max_stability = getMaxStabilityGreedy(reliability, availability)
    print(max_stability)  # Output: 6