'''
Given an array of integers arr, randomly return an index of the maximum value seen by far.

Example:
Input: [11, 30, 2, 30, 30, 30, 6, 2, 62, 62]

Having iterated up to the at element index 5 (where the last 30 is), randomly give an index among [1, 3, 4, 5] which are indices of 30 - the max value by far. 
Each index should have a ¼ chance to get picked.

Having iterated through the entire array, randomly give an index between 8 and 9 which are indices of the max value 62.
'''
'''
Complexity:-
TC :- O(n)
SC :- O(1)
'''
'''
Random Resvoir Sampling
'''
import random
def max_random_index(nums):
    _max = float('-inf')
    max_i = -1
    count = 0

    for i, n in enumerate(nums):
        if n > _max:
            _max = n
            count = 1
            max_i = i
        elif n == _max:
            count += 1
            r = random.randint(1, count)
            if r == 1:
                max_i = i
  
        print(i, max_i)

if __name__ == '__main__':
    print(max_random_index([11, 30, 2, 30, 30, 30, 6, 2, 62, 62]))