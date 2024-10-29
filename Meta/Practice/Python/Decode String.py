'''
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
'''
'''
Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
'''
'''
Complexity:-
TC:- O(n)
O(maxK^countK.n)
Sc:- O(n) for stack space
'''
class Solution:
    def decodeString(self, s: str) -> str:
        # record of tuple ( previous token, repeat times of current token)
        stack = []
        
        cur_token, cur_number =  '', 0
        
        for char in s:
            
            if char == '[':
                # meet start symbol '['
                # save current token and current number into stack
                stack.append( (cur_token, cur_number) )
                
                # clear cur_token for new symbol in [ ]
                cur_token = ''
                
                # clear cur_number for new number in [ ]
                cur_number = 0
                
            elif char == ']':
                # meet ending symbol ']'
                # pop previous token and repeat times of current token from stack
                prev_token, repeat_times = stack.pop()
                
                # update current token with specified repeat times
                cur_token = prev_token + cur_token * repeat_times
                
            elif char.isdigit():
            
                # update current number
                cur_number = cur_number*10 + int(char)
            
            else:
 
                # update current token
                cur_token += char
        return cur_token

'''
Approach:- Recursion
'''
class Solution:
    def decodeString(self, s: str) -> str:       
        def dfs(s,p):
            res = ""
            i,num = p,0
            while i<len(s):
                asc = (ord(s[i])-48)
                if 0<=asc<=9:           # can also be written as if s[i].isdigit()
                    num=num*10+asc
                elif s[i]=="[":
                    local,pos = dfs(s,i+1)
                    res+=local*num
                    i=pos
                    num=0
                elif s[i]=="]":
                    return res,i
                else:
                    res+=s[i]
                i+=1
            return res,i
        
        return dfs(s,0)[0]
