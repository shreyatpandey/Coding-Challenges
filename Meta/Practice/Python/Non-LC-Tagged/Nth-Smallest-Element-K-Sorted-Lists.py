'''
Find the nthe smallest element of K sorted lists
1: [1, 4, 5, 8, 9]
2: [3, 4, 4, 6]
3: [0, 2, 8]
n = 4
Output: 3
'''

'''
TC :- O(n*log(k))
Sc :- O(n) for heap
'''
from heapq import *
 
#  This function takes an array of arrays as an
#  argument and all arrays are assumed to be
#  sorted. It returns m-th smallest element in
#  the array obtained after merging the given
#  arrays.
def mThLargest(arr, m):
 
    #  Create a min heap. Every
    #  heap node has first element of an array
    pq = []
    for i in range(len(arr)):
        heappush(pq, (arr[i][0], (i, 0)))
 
    #  Now one by one get the minimum element
    #  from min heap and replace it with next
    #  element of its array
    count = 0
    while count < m and pq:
        curr = heappop(pq)
 
        #  i ==> Array Number
        #  j ==> Index in the array number
        i = curr[1][0]
        j = curr[1][1]
 
        # The next element belongs to same array as current.
        if j + 1 < len(arr[i]):
            heappush(pq, (arr[i][j + 1], (i, j + 1)))
        count += 1
 
    return arr[i][j]
 
# Driver Code
arr = [[2, 6, 12], [1, 9], [23, 34, 90, 2000]]
m = 4
print(mThLargest(arr, m))