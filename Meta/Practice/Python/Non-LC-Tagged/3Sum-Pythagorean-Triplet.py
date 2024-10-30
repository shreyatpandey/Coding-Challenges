'''
Approach - 1 : Two Pointer
Tc :- O(n^2)
Sc :- O(1)
'''
def pythagoreanTriplet(arr):
    n = len(arr)

    # Taking Square of each element
    for i in range(n):
        arr[i] = arr[i] * arr[i]
    arr.sort()

    # Fix the largest element of Pythagorean triplet
    for i in range(n - 1, 1, -1):
      
        # Two pointer technique to find remaining two 
        # elements such that a^2 + b^2 = c^2
        l = 0
        r = i - 1
        while l < r:
          
            # A Pythagorean triplet is found
            if arr[l] + arr[r] == arr[i]:
                return True

            if arr[l] + arr[r] < arr[i]:
                l += 1
            else:
                r -= 1
    return False

arr = [3, 1, 4, 6, 5]
print(pythagoreanTriplet(arr))

'''
Approach - 2 : 
Tc :- O(max(arr)^2)
Sc :- O(max(arr)
'''
'''
The idea is to generate all possible pairs (a, b) within the range of maximum element in the input array using nested loops. 
For each pair, calculate the value of c required to form a Pythagorean Triplet and check if c exists in the input array.
We can check if c exists or not in constant time by marking all the elements of input array in a visited array. 

Here, we only need to mark the elements and not store their frequency because for all valid triplets of positive integers (a, b, c), 
no two elements can be equal, that is a != b, a != c and b != c.
'''
import math
def pythagoreanTriplet(arr):
    n = len(arr)
    maxEle = 0
    for ele in arr:
        maxEle = max(maxEle, ele)

    # Visited array to mark the elements
    vis = [False] * (maxEle + 1)

    # Marking each element of input array
    for ele in arr:
        vis[ele] = True

    # Iterate for all possible a
    for a in range(1, maxEle + 1):

        # If a is not there
        if not vis[a]:
            continue

        # Iterate for all possible b
        for b in range(1, maxEle + 1):

            # If b is not there
            if not vis[b]:
                continue

            # calculate c value to form a pythagorean triplet
            c = int(math.sqrt(a * a + b * b))

            # If c^2 is not a perfect square or c exceeds the
            # maximum value
            if (c * c) != (a * a + b * b) or c > maxEle:
                continue

            # If there exists c in the original array,
            # we have found the triplet
            if vis[c]:
                return True

    return False

if __name__ == "__main__":
    arr = [3, 1, 4, 6, 5]
    print(pythagoreanTriplet(arr))