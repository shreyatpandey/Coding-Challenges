'''
Passed all ten cases
'''
def minimalHeaviestSetA(arr):
  prefixSum = 0
  for num in arr:
    prefixSum += num

  arr.sort()
  maxNo = 0
  index = 0
  while index < len(arr) and maxNo*2 < prefixSum:
    maxNo += arr[index]
    index += 1

  index -= 1
  result = [0 for i in range(0,len(arr)-index)]
  for i in range(0,len(arr)-index):
    result[i] = arr[index+i]
  
  return result
