'''
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
'''
'''
Example 1:

Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
'''
'''
Constraints:
1 <= n <= 2^31 - 1
'''
'''
Approach:- Floyd's Cycling Algorithm
Complexity:-
Tc:- O(log(n))
Sc:- O(1)
'''
def isHappy(self, n: int) -> bool:  
    def get_next(number):
        total_sum = 0
        while number > 0:
            number, digit = divmod(number, 10)
            total_sum += digit ** 2
        return total_sum

    slow_runner = n
    fast_runner = get_next(n)
    while fast_runner != 1 and slow_runner != fast_runner:
        slow_runner = get_next(slow_runner)
        fast_runner = get_next(get_next(fast_runner))
    return fast_runner == 1

if __name__ == '__main__':
    print("Test Case:1")
    inputNum = 19
    print(happyNumber(19))
    
    print("Test Case:2")
    inputNum = 0
    print(happyNumber(inputNum))
    
    print("Test Case:3")
    inputNum = pow(2,31)-1
    print(happyNumber(inputNum))
'''
Test Case:1
fastPointer: 82
slowPointer: 82
fastPointer: 100
slowPointer: 68
fastPointer: 1
slowPointer: 100
fastPointer: 1
slowPointer: 1
fastPointer: 1
True
Test Case:2
fastPointer: 0
False
Test Case:3
fastPointer: 260
slowPointer: 260
fastPointer: 16
slowPointer: 40
fastPointer: 58
slowPointer: 16
fastPointer: 145
slowPointer: 37
fastPointer: 20
slowPointer: 58
fastPointer: 16
slowPointer: 89
fastPointer: 58
slowPointer: 145
fastPointer: 145
False
'''

'''
Approach:- HashSet
Complexity
Tc:- O(log(n))
Sc:- O(log(n) for hashSet
'''
def isHappy(self, n: int) -> bool:
    def get_next(n):
        total_sum = 0
        while n > 0:
            n, digit = divmod(n, 10)
            total_sum += digit ** 2
        return total_sum

    seen = set()
    while n != 1 and n not in seen:
        seen.add(n)
        n = get_next(n)

    return n == 1
