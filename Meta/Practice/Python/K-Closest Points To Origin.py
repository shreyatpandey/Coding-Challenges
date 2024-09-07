'''
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
'''
'''
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

'''

'''
Approach-1:- Heaps
Time-Complexity:- O(NLogK)
Space-Complexity:- O(k)
Python has min heap
'''
import heapq
import math
h = []
for x,y in points:
   	dist=math.sqrt(x**2+y**2)
   	if len(h)<k:
   		heapq.heappush(h,(-dist,[x,y]))
   	else:
   		heapq.heappushpop(h,(-dist,[x,y]))
   return [h[i][1] for i  in range(k)]

'''
Approach-2:- Quick Select
Time-Complexity:- O(N) best-case
Worst-Case:- O(N^2)
Space-Complexity:- O(1)
'''
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        #quick select O(n), worst case O(n2)
        def partition(l,r,pivot_index):
		
            #1. move pivot to end
            pivot=points[pivot_index][0]**2 +points[pivot_index][1]**2
            points[pivot_index],points[r]=points[r],points[pivot_index]
            
            #2. now start moving elements less than pivot to left and greater to right
            store_index=l
            for i in range(l,r):
                if (points[i][0]**2+points[i][1]**2)<pivot:
                    points[store_index],points[i]=points[i],points[store_index]
                    store_index+=1
					
            #3. now store_index has the place that pivot should be stored in, swap with pivot elemnted which is stored in index r (last element)
            points[store_index],points[r]=points[r],points[store_index]
            return store_index

        
        def select(l,r,k):
            if l<r:
                pivot_index=random.randint(l,r)
                pivot_index=partition(l,r,pivot_index)
				
                if pivot_index==k:
                    return 
                if pivot_index<k:
                    select(pivot_index+1,r,k)
                else:
                    select(l,pivot_index-1,k)
                

        select(0,len(points)-1,k)
        
        return points[:k]
