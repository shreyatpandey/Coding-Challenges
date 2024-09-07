'''
Given an integer array nums with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the array nums.
int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, 
then each index should have an equal probability of returning.
'''
'''
Input:- [1,2,3,3,3]
Is the given array sorted? No
Use Reservoir Sampling - Key Word
Create a random set, and then iterate through the set. If the value of the set is equal to target, increment count.

2 : It's probability of selection is 1 * (1/2) * (2/3) = 1/3
3 : It's probability of selection is (1/2) * (2/3) = 1/3
4 : It's probability of selection is just 1/3

Formula:-
(1 / i) * (1 - 1/ (i + 1)) * (1 - 1/(i + 2)) * ... * (1 - 1 / n) = 1/n

'''
'''
["Solution","pick","pick","pick","pick"]
[[[1,2,3,3,3]],[3],[1],[3],[2]]
Output:
idx,cnt: 4 3
idx,cnt: 0 1
idx,cnt: 2 3
idx,cnt: 1 1

'''
'''
TC:- 
init :- O(1) or O(n)
pic:- O(n)
SC:- O(1) , this may not be coorect

'''
def __init__(self, nums: List[int]):
    self.nums = nums

def pick(self, target: int) -> int:
    cnt = idx = 0
    for i, num in enumerate(self.nums):
        if num != target:
            continue
        if cnt == 0:
            idx = i
            cnt = 1
        else:
            # this random will already give me numbers
            # between 0 and cnt inclusive
            # so for 2nd number I am getting random number 0 and 1
            # so each having a probability of 1/2
            # similarly for three numbers it will be 1/3
            rnd = random.randint(0, cnt)
            if (rnd == cnt):
                idx = i
            cnt += 1
    
    return idx
