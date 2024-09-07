'''
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, 
and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

'''
'''
wording:-
Explanation
Intuition, when adding a new asteroid, there are 2 situation (collision or no collsion)
Collision (left meaning previous asteroid, right meaning current asteroid)
Left destroyed right, e.g. 3, -1
Right destroyed left, e.g. 1, -3
Both destroyed, e.g. 2, -2
No collision
It seems like scenarios can be analyzed linearly with some condition check on neighbors, intuitively, stack is a good tool to use
So let's focus on 3 collision situation, for each new right asteroid
If left destroyed right, then no more to destroy, break
If both destroyed, no more to destroy, break
If right destroyed left, then there is a chance it could destroy more on the left, thus
pop out left from stack, repeat check again
If stack becomes empty, meaning right destroyed all left asteroids, append right to stack
'''
'''
Complexity:-
TC:- O(N)
SC:- O(N)

'''
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        s = []
        for a in asteroids:
            while s and s[-1] > 0 and a < 0:
                if s[-1] + a < 0: s.pop()
                elif s[-1] + a > 0: break    
                else: s.pop(); break
            else: s.append(a)        
        return s
