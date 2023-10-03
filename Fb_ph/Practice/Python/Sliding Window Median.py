'''
Complexity
TC:- O(log(k))
SC:- O(n) for heap
'''
import heapq
class Solution:
        def medianSlidingWindow(self, nums: List[int], k: int):
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
            # print(left_heap, right_heap)
            rolling_medians.append(right_heap[0][0] if k % 2 else
                                   (-left_heap[0][0] + right_heap[0][0]) / 2)
            # now rolling update both heaps
            for i, v in enumerate(nums[k:], k):
                # update
                if v >= right_heap[0][0]:
                    # if value is even larger than the ~ (k/2) th biggest
                    heapq.heappush(right_heap, (v, i))
                    # now this one is really confusing
                    # my explanation: https://leetcode.com/problems/sliding-window-median/discuss/96337/Python-SortedArray-(beats-100)-and-2-Heap(beats-90)-solution/391584
                    if nums[i - k] <= right_heap[0][0]:
                        heapq.heappush(left_heap, (-right_heap[0][0], right_heap[0][1]))
                        heapq.heappop(right_heap)
                else:
                    # pretty much symmetric
                    heapq.heappush(left_heap, (-v, i))
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
