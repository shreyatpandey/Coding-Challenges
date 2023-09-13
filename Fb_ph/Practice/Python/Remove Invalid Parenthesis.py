'''
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.


Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 3:

Input: s = ")("
Output: [""]

'''

'''
Time-Complexity:-
Let n be the number of parentheses in the string.
While doing BFS we handle the states level by level, in the worst case, 
we need to handle all the levels, we can analyze the time complexity level by level and add them up to get the final complexity.

On the first level, there's only one string which is the input string s, let's say the length of it is n, to check whether it's valid, we need O(n) time. 
On the second level, we remove one ( or ) from the first level, so there are C(n, n-1) new strings, each of them has n-1 characters, and for each string,
we need to check whether it's valid or not, thus the total time complexity on this level is (n-1) x C(n, n-1). 
Come to the third level, total time complexity is (n-2) x C(n, n-2), so on and so forth...

Finally we have this formula:

T(n) = n x C(n, n) + (n-1) x C(n, n-1) + ... + 1 x C(n, 1) = n x 2^(n-1)

'''

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        # define when a combination of parenthesis is still valid
        def valid(candidate):
            counter = 0
            for char in candidate:
                if char == "(": counter += 1
                elif char == ")": counter -= 1
                if counter < 0: return False
            # balanced?
            return counter == 0
        # the actual BFS, we return the minimum of removals, so we stop as soon as we have something
        res, frontier = set() , set([s])
        while not res:
            _next = set()
            for candidate in frontier:
                if valid(candidate): res.add(candidate); continue
                # generate more candidates based on this candidate
                for i, letter in enumerate(candidate):
                    # skip trash
                    if letter not in "()": continue
                    _next.add(candidate[:i] + candidate[i+1:])
            frontier = _next
        return res
        
