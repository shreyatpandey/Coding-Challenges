'''
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
'''
'''
Constraints:-
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.

'''
'''
Keep t_counter of char counts in t
We make a sliding window across s, tracking the char counts in s_counter
We keep track of matches, the number of chars with matching counts in s_counter and t_counter
Increment or decrement matches based on how the sliding window changes
When matches == len(t_counter.keys()), we have a valid window. Update the answer accordingly

How we slide the window:
Extend when matches < chars, because we can only get a valid window by adding more.
Contract when matches == chars, because we could possibly do better than the current window.

How we update matches:
This only applies if t_counter[x] > 0.
If s_counter[x] is increased to match t_counter[x], matches += 1
If s_counter[x] is increased to be more than t_counter[x], do nothing
If s_counter[x] is decreased to be t_counter[x] - 1, matches -= 1
If s_counter[x] is decreased to be less than t_counter[x] - 1, do nothing
'''
'''
TC:- O(s + t) where O(t) to build t_counter, then O(s) to move our sliding window across s. Each index is only visited twice.
SC:- O(s + t) where O(t) space for t_counter and O(s) space for s_counter
'''
from collections import Counter
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if not s or not t or len(s) < len(t):
            return ''
        
        t_counter = Counter(t)
        chars = len(t_counter.keys())
        
        s_counter = Counter()
        #print("s_counter:",s_counter)
        matches = 0
        
        answer = ''
        
        i = 0
        j = -1 # make j = -1 to start, so we can move it forward and put s[0] in s_counter in the extend phase 
        
        while i < len(s):
            
            # extend
            if matches < chars:
                
                # since we don't have enough matches and j is at the end of the string, we have no way to increase matches
                if j == len(s) - 1:
                    return answer
                
                j += 1
                s_counter[s[j]] += 1
                #print("s_counter:",s_counter)
                if t_counter[s[j]] > 0 and s_counter[s[j]] == t_counter[s[j]]:
                    print("first condition")
                    matches += 1

            # contract
            else:
                #print("Else condition")
                s_counter[s[i]] -= 1
                if t_counter[s[i]] > 0 and s_counter[s[i]] == t_counter[s[i]] - 1:
                    matches -= 1
                i += 1
                
            # update answer
            if matches == chars:
                if not answer:
                    #print("if not answer")
                    answer = s[i:j+1]
                elif (j - i + 1) < len(answer): #this gives minimum size of window substring
                    answer = s[i:j+1]
                #print("answer:",answer)
                
        return answer
    
if __name__ == '__main__':
    s = "ADOBECODEBANC"
    t = "ABC"
    print("Test-Case:1")
    s1 = Solution()
    print("Result:",s1.minWindow(s,t))

'''
Test-Case:1
s_counter: Counter()
s_counter: Counter({'A': 1})
first condition
s_counter: Counter({'A': 1, 'D': 1})
s_counter: Counter({'A': 1, 'D': 1, 'O': 1})
s_counter: Counter({'A': 1, 'D': 1, 'O': 1, 'B': 1})
first condition
s_counter: Counter({'A': 1, 'D': 1, 'O': 1, 'B': 1, 'E': 1})
s_counter: Counter({'A': 1, 'D': 1, 'O': 1, 'B': 1, 'E': 1, 'C': 1})
first condition
if not answer
answer: ADOBEC
Else condition
s_counter: Counter({'O': 2, 'D': 1, 'B': 1, 'E': 1, 'C': 1, 'A': 0})
s_counter: Counter({'D': 2, 'O': 2, 'B': 1, 'E': 1, 'C': 1, 'A': 0})
s_counter: Counter({'D': 2, 'O': 2, 'E': 2, 'B': 1, 'C': 1, 'A': 0})
s_counter: Counter({'D': 2, 'O': 2, 'B': 2, 'E': 2, 'C': 1, 'A': 0})
s_counter: Counter({'D': 2, 'O': 2, 'B': 2, 'E': 2, 'A': 1, 'C': 1})
first condition
answer: ADOBEC
Else condition
answer: ADOBEC
Else condition
answer: ADOBEC
Else condition
answer: ADOBEC
Else condition
answer: ADOBEC
Else condition
s_counter: Counter({'A': 1, 'D': 1, 'O': 1, 'B': 1, 'E': 1, 'N': 1, 'C': 0})
s_counter: Counter({'A': 1, 'D': 1, 'O': 1, 'B': 1, 'E': 1, 'C': 1, 'N': 1})
first condition
answer: ADOBEC
Else condition
answer: ADOBEC
Else condition
answer: EBANC
Else condition
answer: BANC
Else condition
Result: BANC
'''
