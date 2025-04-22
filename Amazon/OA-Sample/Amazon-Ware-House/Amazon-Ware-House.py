import heapq

def getMinimumDockBays(truckCargoSize, maxTurnaroundTime):
    """
    Finds the minimum number of dock bays needed to unload all trucks
    within the given timeframe.

    Args:
      truckCargoSize: A list of integers representing the time in minutes
                      to unload each truck.
      maxTurnaroundTime: The maximum allowed total unloading time.

    Returns:
      The smallest number of dock bays d, to unload all the cargo within
      maxTurnaroundTime minutes.
    """
    n = len(truckCargoSize)

    # Binary search for the minimum number of dock bays.
    # The lower bound is 1 (at least one dock bay is needed).
    # The upper bound is n (in the worst case, each truck needs its own bay).
    low = 1
    high = n
    minimum_dock_bays = n # Initialize with a possible maximum

    while low <= high:
        mid = (low + high) // 2  # Number of dock bays to test

        # Simulate the unloading process with 'mid' dock bays.
        # Use a min-heap to keep track of the finish times of each dock bay.
        # Initially, all dock bays are free at time 0.
        dock_bay_finish_times = [0] * mid
        heapq.heapify(dock_bay_finish_times)

        current_finish_time = 0

        # Assign trucks to the earliest available dock bay.
        for cargo_size in truckCargoSize:
            # Get the earliest time a dock bay becomes free.
            earliest_free_time = heapq.heappop(dock_bay_finish_times)

            # The current truck starts unloading at this time.
            start_time = earliest_free_time

            # The truck finishes unloading at start_time + cargo_size.
            finish_time = start_time + cargo_size

            # Push the new finish time back to the heap for this dock bay.
            heapq.heappush(dock_bay_finish_times, finish_time)

            # Keep track of the latest finish time among all trucks.
            current_finish_time = max(current_finish_time, finish_time)

        # Check if all trucks were unloaded within the maximum allowed time.
        if current_finish_time <= maxTurnaroundTime:
            # If successful, it might be possible with fewer dock bays.
            minimum_dock_bays = mid
            high = mid - 1
        else:
            # If not successful, more dock bays are needed.
            low = mid + 1

    return minimum_dock_bays

# Example Test Case
n = 5
truckCargoSize = [3, 4, 3, 2, 3]
maxTurnaroundTime = 8
expected_output = 3

actual_output = getMinimumDockBays(truckCargoSize, maxTurnaroundTime)

print(f"Truck Cargo Sizes: {truckCargoSize}")
print(f"Maximum Turnaround Time: {maxTurnaroundTime}")
print(f"Expected Minimum Dock Bays: {expected_output}")
print(f"Actual Minimum Dock Bays: {actual_output}")

assert actual_output == expected_output, f"Test failed. Expected: {expected_output}, Got: {actual_output}"