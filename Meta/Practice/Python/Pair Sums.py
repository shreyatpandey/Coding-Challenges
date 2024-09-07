'''
Input List consist of Duplicates
'''

from collections import Counter
def numberOfWays(arr, k): #return noOfPairs
   # Write your code here
  count = Counter(arr)
  noOfPairs = 0
  for index,num in enumerate(arr):
      noOfPairs += count[k-num]
      if k - num == num:
        noOfPairs -= 1

  return noOfPairs//2

def numberOfWays(arr,k): # return list of pairs this is difficult to get
    count = Counter(arr)
    Result = []
    for index in range(arr):
        noOfPairs += count[k-num]
        if k - num == num:
            noOfPairs -= 1
        if count[k-num]:
            


if __name__ == '__main__':
    print("TestCase-1:")
    inputList = [1,5,3,3,3]
    k = 6
    print(numberOfWays(inputList,k))
    print("TestCase-2:")
    k = 6
    arr = [1, 2, 3, 4, 3]
    print(numberOfWays(arr,k))
    
