'''
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
'''
'''
Constraints:
1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
'''
'''
Input:-
Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
'''
'''
Wording:-
Explanation of Input:-
(1) s = "aa" , p = "a"
If '*' or '.' it is as good as string match

(2)
'.' - period can be any character
'ab' = 'a.' as '.' can take any character

(3) s = "aa" , p ="a*"
p can repeat infinite times as = ["","a","aa","aaa","aaaaa"]

(4) ".*" <=> ["",".","..","..."] and "." can represent any character

The complexity comes from the "*" and "." as dot simply represents any character

Basic Intuitive Approach is to develop a Decision tree
say for a* two choices "",a -> "aa","" and TC:- O(2^n)
If we cache this, then we would bring down this TC:- O(M*N)

Whenever we encounter "*", either I can use the star or not use the star
If we choose not to use the star, we would increment the j pointer by 2 that is j = j +2

Question:-
What is p is out of bound with respect to the length of the string = s
Consecutively, what if s is out of bound with respect to the length of string = p

'''
'''
Top-Down - Memoization
TC:- O(M*N)
where M is the length of string = s and N is the length of string = p
SC:- O(M*N)
'''
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        cache = {}
        def dfs(i,j):
            if (i,j) in cache:
                return cache[(i,j)]
            
            if i>=len(s) and j>=len(p):
                return True
            
            if j>=len(p):
                return False
            
            match = i<len(s) and (s[i]==p[j] or p[j] == '.')
            #print("match:",match)
            if (j+1)<len(p) and p[j+1] == '*' :   #the reason for checking "*" is that it has the highesh precedence and j+1 because the firsr character can never be "*"
                #whenever we encounter "*" we have two choices use or dont use it
                #print("1:(i,j)",i,j)
                cache[(i,j)] = (dfs(i,j+2) or  #dont use *
                        (match and dfs(i+1,j))) #use *
                return cache[(i,j)]
            if match:
                #print("2:(i,j)",i,j)
                cache[(i,j)] = dfs(i+1,j+1)
                return cache[(i,j)]
            cache[(i,j)] = False
            return False
        
        return dfs(0,0)
if __name__ == '__main__':
    print("Test Case-1:")
    s,p = "aa", "a*"
    object1 = Solution()
    print("Result:", object1.isMatch(s,p))
    
'''
Test Case-1:
match: True
1:(i,j) 0 0
match: True
1:(i,j) 1 0
match: False
1:(i,j) 2 0
Result: True
'''


'''
Approach:- Bottom-Up
TC:- O(M*N)
SC:- O(M*N)
'''
    
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
         # The DP table and the string s and p use the same indexes i and j, but
        # table[i][j] means the match status between p[:i] and s[:j], i.e.
        # table[0][0] means the match status of two empty strings, and
        # table[1][1] means the match status of p[0] and s[0]. Therefore, when
        # refering to the i-th and the j-th characters of p and s for updating
        # table[i][j], we use p[i - 1] and s[j - 1].

        # Initialize the table with False. The first row is satisfied.
        table = [[False] * (len(s) + 1) for _ in range(len(p) + 1)]

        # Update the corner case of matching two empty strings.
        table[0][0] = True

        # Update the corner case of when s is an empty string but p is not.
        # Since each '*' can eliminate the charter before it, the table is
        # vertically updated by the one before previous. [test_symbol_0]
        for i in range(2, len(p) + 1):
            table[i][0] = table[i - 2][0] and p[i - 1] == '*'

        for i in range(1, len(p) + 1):
            for j in range(1, len(s) + 1):
                if p[i - 1] != "*":
                    # Update the table by referring the diagonal element.
                    table[i][j] = table[i - 1][j - 1] and \
                                  (p[i - 1] == s[j - 1] or p[i - 1] == '.')
                else:
                    # Eliminations (referring to the vertical element)
                    # Either refer to the one before previous or the previous.
                    # I.e. * eliminate the previous or count the previous.
                    # [test_symbol_1]
                    table[i][j] = table[i - 2][j] or table[i - 1][j]

                    # Propagations (referring to the horizontal element)
                    # If p's previous one is equal to the current s, with
                    # helps of *, the status can be propagated from the left.
                    # [test_symbol_2]
                    if p[i - 2] == s[j - 1] or p[i - 2] == '.':
                        table[i][j] |= table[i][j - 1]

        return table[-1][-1]
'''
std::map< std::pair<std::string, std::string>, bool > invalidCases = {
        { {"aab", "c*a*b"}, true },
        { {"mississippi", "mis*is*p*."}, false },
        { {"aaa", "ab*ac*a"}, true },
        { {"aaa", "ab*a*c*a"}, true },
        { {"aaca", "ab*a*c*a"}, true },
        { {"a", "ab*"}, true },
        { {"bbbba", ".*a*a"}, true },
        { {"ab", ".*.."}, true },
        { {"ab", ".*..c*"}, true },
        { {"a", ".*."}, true },
        { {"aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s"}, true },
        { {"abbbcd", "ab*bbbcd"}, true },
        { {"bbab", "b*a*"}, false },
        { {"a", "c*."}, true },
        { {"a", "c*a"}, true },
        { {"b", "a*."}, true },
        { {"a", ".*a*"}, true },
        { {"a", "..*"}, true },
        { {"aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*"}, true },
        { {"abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*"}, true },
        { {"bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*"}, true },
        { {"baabbbaccbccacacc", "c*..b*a*a.*a..*c"}, true },
        { {"abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*"}, true },
        { {"cbaacacaaccbaabcb", "c*b*b*.*ac*.*bc*a*"}, true },
        { {"cbaacacaaccbaabcb", "c*b*b*.*ac*.*bc*a*"}, true },
        { {"cabbbbcbcacbabc", ".*b.*.ab*.*b*a*c"}, true },
        { {"abbcacbbbbbabcbaca", "a*a*.*a*.*a*.b*a*"}, true },
        { {"aababbabacaabacbbbc", ".b*ac*.*c*a*b*.*"}, true },
        { {"aaabaaaababcbccbaab", "c*c*.*c*a*..*c*"}, true },
        { {"cbccaababcbabac", "c*aab*.*b.b.*.*a*."}, false },
        { {"caccccaccbabbcb", "c*c*b*a*.*c*.a*a*a*"}, true },
        { {"bbbaccbbbaababbac", ".b*b*.*...*.*c*."}, true },
        { {"ccbbcabcbbaabaccc", "c*a*.*a*a*.*c*b*b*."}, true },
        { {"abbaaaabaabbcba", "a*.*ba.*c*..a*.a*."}, true },
        { {"bbcacbabbcbaaccabc", "b*a*a*.c*bb*b*.*.*"}, true },
        { {"aabccbcbacabaab", ".*c*a*b.*a*ba*bb*"}, true },
        { {"cbbbaccbcacbcca", "b*.*b*a*.a*b*.a*"}, true },
        { {"cbacbbabbcaabbb", "b*c*.*a*..a.*c*.*"}, true },
        { {"abaabababbcbcabbcbc", "b*ab.*.*.*.b..*"}, true },
        { {"caaacccbaababbb", "c*.*b*ba*ac*c*b*.*"}, true },
        { {"abbbaabccbaabacab", "ab*b*b*bc*ac*.*bb*"}, true },
        { {"abbbaabccbaabacab", "ab*b*b*bc*ac*.*bb*"}, true },
        { {"cacbacccbbbccab", ".b*b*.*c*a*.*bb*"}, true },
        { {"abcbccbcbaabbcbb", "c*a.*ab*.*ab*a*..b*"}, true },
        { {"caabbabbbbccccbbbcc", ".b*c*.*.*bb*.*.*"}, true },
        { {"caaccabbbabcacaac", "b*c*b*b*.b*.*c*a*c"}, true },
        { {"cbcaabcbaabccbaa", "c*b*ab*.*b*c*a*"}, false },
        { {"bccbcccbcbbbcbb", "c*c*c*c*c*.*.*b*b*"}, true },
        { {"ccacbcbcccabbab", ".c*a*aa*b*.*b*.*"}, true },
        { {"aabbcbcacbacaaccacc", "c*b*b*.*.*.*a*.*"}, true },
        { {"bcbabcaacacbcabac", "a*c*a*b*.*aa*c*a*a*"}, true },
        { {"acabbabacaccacccabc", "a*.*c*a*.b.*a*.*"}, true },
        { {"babbcccbacaabcbac", "b.*.*c*b*b*.*c*c"}, true },            
        { {"cbbbbabaabbacbbc", "a*c*b*.*bb*a*.*a*"}, true },            
        { {"accbabbacbbbacb", ".*.*.*a*bba*ba*"}, false },
        { {"ababbcaaabbaccb", "c*c*..*a*a*a*.*"}, true },
        { {"bcabcbcaccabcbb", "a*a*c*a*.*a*c*bc*."}, true },
        { {"bcbbbacbabccbabbac", "c*.*b*a.*a*a*a*"}, true },
        { {"ccbbbbbacacaaabcaa", ".*ba*.*.b*c*c*b*a.*"}, true },
        { {"acaababbccbaacabcab", "..*bb*b*c*a*c*.*.b"}, true },
        { {"cbabcabbbacbcaca", "a*c*.*a*a*b*c*a*.*"}, true },
        { {"bacacaababbbcbc", ".*a*.*a*.aa*c*b*c"}, false },
        { {"cbabcbbaabbcaca", ".a*b*.*.*b*c*.*b*a*"}, true },
        { {"bbaaaacabccbcac", "b*b*a*c*c*a*c*.*"}, true },
        { {"bcccccbaccccacaa", ".*bb*c*a*b*.*b*b*c*"}, true },
        { {"bcbaccbbbccabaac", "c*.*a*b*ac*a*a*"}, true },
        { {"bacacbacaaabccbcbaa", "a*.c*c*c*a*b*..*"}, true },
        { {"baccbbcbcacacbbc", "c*.*b*c*ba*b*b*.a*"}, true },

    };
    '''
