'''
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
'''
'''
Constraints:
n == ratings.length
1 <= n <= 2 * 10^4
0 <= ratings[i] <= 2 * 10^4
'''
'''
Approach-1:- Two Pass Greedy
TC:- O(n), because we make two passes through an array
SC:- O(n), for storing the candies
'''
'''
What is a Greedy Algorithm?
A Greedy Algorithm makes choices that seem optimal at the moment.
For this problem, we use a two-pass greedy approach to make sure each child gets the minimum number of candies that still satisfy the conditions.

The Nuts and Bolts of the Two-Pass Method
Initialize Candies Array
We start by creating a candies array of the same length as the ratings array and initialize all its values to 1. 
This is the base case and ensures that every child will receive at least one candy, satisfying the first condition.

Forward Pass: Left to Right
Now, we iterate through the ratings array from the beginning to the end. 
For each child (except the first), we compare their rating with the one to the left. 
If it's higher, we update the candies array for that child to be one more than the child on the left. 
This takes care of the second condition but only accounts for the child's left neighbor.

Backward Pass: Right to Left
After the forward pass, we loop through the array again but in the reverse direction.
This time, we compare each child's rating with the child to their right. 
If the rating is higher, we need to make sure the child has more candies than the right neighbor. 
So, we update the candies array for that child to be the maximum between its current number of candies and one more than the right neighbor's candies. 
This ensures that both neighboring conditions are checked and satisfied.

Summing it All Up
Finally, we sum up all the values in the candies array. 
This will give us the minimum total number of candies that need to be distributed to satisfy both conditions.
'''
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n 

        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1

        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                candies[i] = max(candies[i], candies[i+1] + 1)
        
        return sum(candies)

'''
Approach-2:- One pass greedy solution, Up-Down-Peak Method
TC:- O(n)
SC:- O(1)
'''
'''
Why Up, Down, and Peak?
The essence of the one-pass greedy algorithm lies in these three variables: Up, Down, and Peak.
They serve as counters for the following:

Up: Counts how many children have increasing ratings from the last child. 
This helps us determine how many candies we need for a child with a higher rating than the previous child.

Down: Counts how many children have decreasing ratings from the last child. 
This helps us determine how many candies we need for a child with a lower rating than the previous child.

Peak: Keeps track of the last highest point in an increasing sequence. 
When we have a decreasing sequence after the peak, we can refer back to the Peak to adjust the number of candies if needed.

How Does it Work?
Initialize Your Counters
Start with ret = 1 because each child must have at least one candy. Initialize up, down, and peak to 0.
Loop Through Ratings
For each pair of adjacent children, compare their ratings. Here are the scenarios:

If the rating is increasing: 
Update up and peak by incrementing them by 1. 
Set down to 0. 
Add up + 1 to ret because the current child must have one more candy than the previous child.

If the rating is the same: 
Reset up, down, and peak to 0, because neither an increasing nor a decreasing trend is maintained. 
Add 1 to ret because the current child must have at least one candy.

If the rating is decreasing: Update down by incrementing it by 1. Reset up to 0. 
Add down to ret. 
Additionally, if peak is greater than or equal to down, decrement ret by 1. 
This is because the peak child can share the same number of candies as one of the children in the decreasing sequence, 
which allows us to reduce the total number of candies.

Return the Total Candy Count
At the end of the loop, ret will contain the minimum total number of candies needed for all the children, so return ret.
By using up, down, and peak, we can efficiently traverse the ratings list just once, 
updating our total candies count (ret) as we go.
This method is efficient and helps us solve the problem in a single pass, with a time complexity of O(n).
'''
class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0
        
        ret, up, down, peak = 1, 0, 0, 0
        
        for prev, curr in zip(ratings[:-1], ratings[1:]):
            if prev < curr:
                up, down, peak = up + 1, 0, up + 1
                ret += 1 + up
            elif prev == curr:
                up = down = peak = 0
                ret += 1
            else:
                up, down = 0, down + 1
                ret += 1 + down - int(peak >= down)
        
        return ret
        
        
