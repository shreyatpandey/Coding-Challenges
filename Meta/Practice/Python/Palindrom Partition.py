'''
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
'''
'''
Algorithm

In the backtracking algorithm, we recursively traverse over the string in depth-first search fashion. 
For each recursive call, the beginning index of the string is given as start.

Iteratively generate all possible substrings beginning at index start.
The index end increments from start until the end of the string.

For each of the substrings generated, check if it is a palindrome.

If the substring is a palindrome, the substring is a potential candidate.
Add the substring to the currentList and perform a depth-first search on the remaining substring. 
If the current substring ends at index end, end+1 becomes the start index for the next recursive call.

Backtrack if start index is greater than or equal to the string length and add the currentList to the result.

'''
'''
Let n be the lenght of the string .
At each step we need to make a decision tree, hence 2^N
TC :- O(N.2^N)
SC :- O(N) for recursion stack
'''
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        result = []
        self. palindrome_partition(s,[],result)
        return result
    
    def check_palindrome(self,string):
        return string == string[::-1]
    
    def palindrome_partition(self,s,path,result):
        if not s:
            result.append(path)
            return result
        for i in range(1,len(s)+1):
            if self.check_palindrome(s[:i]):
                self.palindrome_partition(s[i:], path+[s[:i]], result)
    