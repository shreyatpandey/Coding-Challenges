def max_ascents(ratings):
  """
  Finds the maximum possible number of indices i such that ratings[i] < ratings[i+1]
  after rearranging the array optimally.

  Args:
    ratings: A list of integers representing the ratings.

  Returns:
    The maximum number of indices i such that ratings[i] < ratings[i+1].
  """
  n = len(ratings)
  if n < 2:
    return 0

  ratings.sort()
  ascents = 0
  j = 0  # Pointer for the element we are trying to be greater than

  for i in range(n):
    # If the current element is greater than the element at pointer j,
    # we can form an ascent.
    if ratings[i] > ratings[j]:
      ascents += 1
      j += 1 # Move the pointer j to the next element

  return ascents

# Test Cases
test_cases = [
    ([2, 1, 3], 3, 2),
    ([2, 1, 1, 2], 4, 2),
]
if __name__ == "__main__":
  print(max_ascents([2, 1, 3])) # Output : 2
  print(max_ascents([2, 1, 1, 2])) # Output: 2
  print(max_ascents([2,3,1,5,4])) # Output: 4