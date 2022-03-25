'''
You are given an array arr of N integers. 
For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:
The value at index i must be the maximum element in the contiguous subarrays, and
These contiguous subarrays must either start from or end on index i.

arr = [3, 4, 1, 6, 2]
output = [1, 3, 1, 5, 1]
Explanation:
For index 0 - [3] is the only contiguous subarray that starts (or ends) with 3, and the maximum value in this subarray is 3.
For index 1 - [4], [3, 4], [4, 1]
For index 2 - [1]
For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1, 6]
For index 4 - [2]

'''
def count_subarrays(arr):
  # Write your code here
  maxValue = 0
  length = len(arr)
  result = [1]*length
  stack = [];

  for i in range(length):
    while stack and arr[stack[len(stack) - 1]] < arr[i] : 
        result[i] +=  result[stack.pop()]
    stack.append(i);


  stack = [];
  tmp = [1]*length
  for i in range(length-1,-1,-1):
    while stack and arr[stack[len(stack) - 1]] < arr[i] :
        tmp[i] +=  tmp[stack.pop()];
    stack.append(i);
    result[i] += (tmp[i] - 1);


  return result;
