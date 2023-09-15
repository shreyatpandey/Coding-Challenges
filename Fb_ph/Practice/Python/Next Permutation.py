'''
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
then the next permutation of that array is the permutation that follows it in the sorted container
Input:- 
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
'''
'''
Sequence of the number:-
123
132
213
231
312
321
'''
'''
Wording
Do a linear reverse traversal and find the index for the last ascending position
    - Intuition :- Break into sorted order
By comparing the element with element on its right since we are traversing in reverse order
swap the numbers between the last index and the index for the last ascending position
Perform the reversal of the from the index for the last ascending position to the last
'''
'''
Time-Complexity:- O(N)
Space-Complexity :- O(1)
'''
def nextPermutation(nums):
    i = j = len(nums)-1
    while i > 0 and nums[i-1] >= nums[i]:
        i -= 1
    if i == 0:   # nums are in descending order
        nums.reverse()
        return
    print("i:",i)
    k = i - 1    # find the last "ascending" position
    while nums[j] <= nums[k]:
        j -= 1
    print("k:",k)
    nums[k], nums[j] = nums[j], nums[k]  
    l, r = k+1, len(nums)-1  # reverse the second part
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l +=1 ; r -= 1

if __name__ == '__main__':
    print("Test Case-1:")
    nums = [1,2,3]
    nextPermutation(nums)
    print(nums)
    
    print("Test Case-2:")
    nums = [2,1,3]
    nextPermutation(nums)
    print(nums)
    
    print("Test Case-3:")
    nums = [3,2,1]
    nextPermutation(nums)
    print(nums)
    
'''
Test Case-1:
i: 2
k: 1
[1, 3, 2]
Test Case-1:
i: 2
k: 1
[2, 3, 1]
Test Case-3:
[1, 2, 3]
'''
