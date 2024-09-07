'''
Complexity
TC:- O(log(k))
SC:- O(k) for heap
'''
'''
I forgot, median is always taken for ordered and sorted list/array
The given window size could have elements which are not sorted
'''
import heapq
class Solution:
    def medianSlidingWindow(self, nums, k):
        left_heap, right_heap, rolling_medians = [], [], []

        # create initial left and right heaps
        # left is max heap and right is minimum heap
        # right heap can have 0 or 1 more element than left
        # therefore median is the average of two heap tops or the right heap

        for i, v in enumerate(nums[:k]):
            # this is a syntactic sugar in that
            # tuple comparison starts by the first entry onward
            # using -v as the first entry essentially creates
            # a max heap
            # note that the native heap implementation is min heap
            heapq.heappush(left_heap, (-v, i))
        
        print("1:left_heap:",left_heap)
        print("k-k//2:",k-k//2)
        
        for i in range(k - k // 2):
            # pop item from left heap and push it to right heap
            # do it for approx half k times
            # the right heap is a min heap
            # therefore the half biggest elements are pushed to
            # the right heap to form a min heap
            # so the top element of the left is now ~(k/2) th smallest
            # and the right top is now ~ (k/2) th biggest
            popped_from_left = heapq.heappop(left_heap)
            heapq.heappush(right_heap, (-popped_from_left[0],
                                        popped_from_left[1]))
        
        print("2:left_heap:", left_heap)
        print("1:right_heap:", right_heap)
        rolling_medians.append(right_heap[0][0] if k % 2 else
                               (-left_heap[0][0] + right_heap[0][0]) / 2)
        print("Rolling Medians:", rolling_medians)
        
        # now rolling update both heaps
        for i, v in enumerate(nums[k:], k):
            #i starts from k, correspondingly v starts from nums[i]
            print("i,v:", i,v)
            
            # update
            if v >= right_heap[0][0]:
                # if value is even larger than the ~ (k/2) th biggest
                heapq.heappush(right_heap, (v, i))
                print("2:right_heap:", right_heap)
                
                # now this one is really confusing
                # my explanation: https://leetcode.com/problems/sliding-window-median/discuss/96337/Python-SortedArray-(beats-100)-and-2-Heap(beats-90)-solution/391584
                if nums[i - k] <= right_heap[0][0]:
                if nums[i - k] <= right_heap[0][0]:
                    heapq.heappush(left_heap, (-right_heap[0][0], right_heap[0][1]))
                    heapq.heappop(right_heap)
            
            else:
                # pretty much symmetric
                heapq.heappush(left_heap, (-v, i))
                print("3:left_heap:",left_heap)
                
                if nums[i - k] >= right_heap[0][0]:
                    heapq.heappush(right_heap, (-left_heap[0][0], left_heap[0][1]))
                    heapq.heappop(left_heap)
            
            # delete out of window keys in the last step
            while left_heap and left_heap[0][1] <= i - k:
                heapq.heappop(left_heap)
            while right_heap and right_heap[0][1] <= i - k:
                heapq.heappop(right_heap)
            rolling_medians.append(right_heap[0][0] if k % 2 else
                                   (-left_heap[0][0] + right_heap[0][0]) / 2)

        return rolling_medians
    
if __name__ == '__main__':
    s = Solution()
    print("Test Case - 1:")
    Input = [1,3,-1]
    k = 2
    print("Answer-1:", s.medianSlidingWindow(Input,k))
    
    print('\n')
    print("Test Case - 2:")
    Input = [1,3,-1,-3,5,3,6,7]
    k = 3
    print("Answer-2:",s.medianSlidingWindow(Input,k))

'''
Output:-
Test Case - 1:
1:left_heap: [(-3, 1), (-1, 0)]
k-k//2: 1
2:left_heap: [(-1, 0)]
1:right_heap: [(3, 1)]
Rolling Medians: [2.0]
i,v: 2 -1
3:left_heap: [(-1, 0), (1, 2)]
Answer-1: [2.0, 1.0]


Test Case - 2:
1:left_heap: [(-3, 1), (-1, 0), (1, 2)]
k-k//2: 2
2:left_heap: [(1, 2)]
1:right_heap: [(1, 0), (3, 1)]
Rolling Medians: [1]
i,v: 3 -3
3:left_heap: [(1, 2), (3, 3)]
i,v: 4 5
2:right_heap: [(-1, 2), (3, 1), (1, 0), (5, 4)]
i,v: 5 3
2:right_heap: [(-1, 2), (3, 1), (1, 0), (5, 4), (3, 5)]
i,v: 6 6
2:right_heap: [(3, 5), (5, 4), (6, 6)]
i,v: 7 7
2:right_heap: [(5, 4), (6, 6), (7, 7)]
Answer-2: [1, -1, -1, 3, 5, 6]
'''
