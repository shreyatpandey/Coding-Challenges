'''
They asked variation of the combination of telephone letter.
Again, the mapping is given. Input is the combination of digits.
Output is the combination of input. 
However, if there is consequtive duplicate numbers such as [1,1], the combination is ['AA' or 'B'].
mapping = {1 -> ['A', 'B', 'C'],
2 -> ['D', 'E', 'F'],
3 -> ['G', 'H', 'I'],
4 -> ['J', 'K', 'L'],
5 -> ['M', 'N', 'O'],
6 -> ['P', 'Q', 'R'],
7 -> ['S', 'T'],
8 -> ['U', 'V', 'W'],
9 -> ['X', 'Y'],
0 -> ['Z']}


E.g. 1: Input: [1, 1, 2] Output: ["AAD" , "BD"]
E.g. 2: Input: [1, 1, 1, 2] Output: ["AAAD", "ABD", "CD", "BAD"]
'''
class Solution:
    def __init__(self, mapping):
        self._mapping = mapping
        self.res = []

    def all_combination_util(self, nums, start_idx, word):
        if start_idx >= len(nums):
            return word
        for i in range(len(self._mapping[nums[start_idx]])):
            if start_idx + i < len(nums) and nums[start_idx+i] == nums[start_idx]:
                composed_word = self.all_combination_util(nums, start_idx+i+1, word + self._mapping[nums[start_idx]][i])
                if composed_word is not None:
                    self.res.append(composed_word)
            else:
                break

    def get_all_combinations(self, nums):
        self.all_combination_util(nums, 0, "")
        return self.res

if __name__ == '__main__':
    map = {1 : ['A', 'B', 'C'],
           2 :  ['D', 'E', 'F'],
           3 : ['G', 'H', 'I'],
           4 : ['J', 'K', 'L'],
           5 : ['M', 'N', 'O'],
           6 : ['P', 'Q', 'R'],
           7 : ['S', 'T'],
           8 : ['U', 'V', 'W'],
           9 : ['X', 'Y'],
           0 : ['Z']
          }
    s= Solution(map)
    nums = [1,1,2]
    print(s.get_all_combinations(nums))
