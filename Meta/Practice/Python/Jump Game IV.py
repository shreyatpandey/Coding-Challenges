'''
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.
Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
'''
'''
Constraints:
1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
'''

'''
Approach:-
Step 1: Initialize data structures
The first step is to initialize few data structures that will be used later in the algorithm.
Create a map to store the indices of each value in the input array, a queue to store the indices of the current nodes to be visited,
and a boolean array to mark whether each index has been seen before:

Step 2: Build the graph
Next step is to build a graph that represents the relationships between the elements in the input array. 
And loop through the array and add each index to the list of indices for its corresponding value in the map:

Step 3: BFS Algorithm
Now, in this step enter a loop that performs a BFS algorithm to find the minimum number of jumps needed to reach the end of the array.
At each iteration of the loop, dequeue the next node from the queue, check if it's the last index of the array, and mark it as visited.
Then add the adjacent nodes to the list of indices for their corresponding value in the map,
and enqueue any adjacent nodes that have not been visited yet:

Step 4: Return the minimum number of jumps
If the end of the array is reached, return the number of steps it took to get there. Otherwise, throw an error:

'''
'''
Complexity:-
TC:- O(N+k)
SC:- O(N+k)
'''
class Solution:
  def minJumps(self, arr: List[int]) -> int:
    n = len(arr)
    # {num: indices}
    graph = collections.defaultdict(list)
    steps = 0
    q = collections.deque([0])
    seen = {0}

    # Create graph where keys are elements and values are their indices in arr
    for i, a in enumerate(arr):
      graph[a].append(i)

    # BFS
    while q:
      # Process all nodes at current level
      for _ in range(len(q)):
        i = q.popleft()
        # If last index is reached, return number of steps
        if i == n - 1:
          return steps
        seen.add(i)
        u = arr[i]
        # Add adjacent indices to graph
        if i + 1 < n:
          graph[u].append(i + 1)
        if i - 1 >= 0:
          graph[u].append(i - 1)
        # Process all adjacent nodes
        for v in graph[u]:
          if v in seen:
            continue
          q.append(v)
        # Clear indices in graph to avoid revisiting
        graph[u].clear()
      steps += 1
