'''
Given a string num that contains only digits and an integer target,
return all possibilities to insert the binary operators '+', '-', and/or '*' 
between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.

'''

'''
TC:- O(4^N) 
why 4 because we have 4 different possible ways to recur
SC:- O(N) for the space required for the recursion stack
'''
'''
TC- Explanation
Total number of valid expressions as per author are O(N^2 x 3^N). But following proof says otherwise.

T(N) = Total Number of Valid Expressions

T(N) = 3T(N - 1) + 3T(N - 2) + 3T(N - 3) + .... 3T(0)

If we use first digit as an operand, total number of valid expressions would be T(N - 1) x 3. Three accounts
for our three operations. If we use first two digits as an operand, total number of valid expressions would be T(N - 2) x 3 and so on.

Now T(N - 1) = 3T(N - 2) + 3T(N - 3) + 3T(N - 4) + .... 3T(0)

if we put T(N - 1) in T(N) we'll get

T(N) = 3 x 4 ( T(N - 2) + T(N - 3) + T(N - 4) + .... T(0) )

If we put T(N - 2) in T(N) we'll get

T(N) = 3 x 4^2 ( T(N - 3) + T(N - 4) + T(N - 5) + .... T(0) )

If we generalize it, we'll get

T(N) = 3 x 4^k ( T(N - (k + 1)) + T(N - (k + 2)) + .... T(0))

If we put k = N - 1, we'll get

T(N) = 3 x 4^(N - 1) (T(0)) = O(4^N)

So Total valid expressions are O(4^N). Not sure how author deduce O(N^2 x 3^N)


'''
'''
Input
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
'''

class Solution:
    def addOperators(self, s: str, target: int) -> List[str]:
        def backtrack(i, path, resultSoFar, prevNum):
            if i == len(s):
                if resultSoFar == target:
                    ans.append(path)
                return

            for j in range(i, len(s)):
                if j > i and s[i] == '0': break  # Skip leading zero number
                num = int(s[i:j + 1])
                if i == 0:
                    backtrack(j + 1, path + str(num), resultSoFar + num, num)  # First num, pick it without adding any operator
                else:
                    backtrack(j + 1, path + "+" + str(num), resultSoFar + num, num)
                    backtrack(j + 1, path + "-" + str(num), resultSoFar - num, -num)
                    backtrack(j + 1, path + "*" + str(num), resultSoFar - prevNum + prevNum * num, prevNum * num)  # Can imagine with example: 1+2*3*4

        ans = []
        backtrack(0, "", 0, 0)
        return ans
