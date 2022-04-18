'''
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. 
More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.
'''
'''
Constraints:-
n == heights.length
1 <= n <= 105
1 <= heights[i] <= 105
All the values of heights are unique.
'''


'''
Explanation
We maintain a decreasing mono stack,
(I stored the index of elements)

As we iterate each element a in input array A,
assume the last element in the stack has index i.
If the last element A[i] <= a,
A[i] can see a,
so we increment res[i]++

Because a is tall and block the line of sight.
A[i] can't see any element after a,
we have done the work for A[i],
so we stack.pop() it from the stack.

We keep doing this while A[i] < a, where i = stack.top().
By doing this, if stack is not empty,
A[i] will be the left next greater element of a.
A[i] can still see a,
so we increment res[i]++.

We do the above for each element a in A,
and we finally return result res


'''
'''
Complexity:
Time O(n)
Space O(n)
'''


class Solution(object):
    def canSeePersonsCount(self, A):
        """
        :type heights: List[int]
        :rtype: List[int]
        """
        res = [0] * len(A)
        stack = []
        for i, v in enumerate(A):
            while stack and A[stack[-1]] <= v:
                res[stack.pop()] += 1
            if stack:
                res[stack[-1]] += 1
            stack.append(i)
        return res
        
