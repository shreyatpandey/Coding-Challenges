'''
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, 
you should store the sparse vector efficiently and compute the dot product between two SparseVector.
Follow up: What if only one of the vectors is sparse?

'''
'''
Constraints:-
Example 1:
Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
'''
'''
Constraints:
n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100
'''


'''
Approach-1:
TC:- O(Len(Dictionary))
SC:- O(Dictionary)
More memory efficient as we are storing non zero values
What if hash function sucks/bad?
This isnt also the best solution
'''
class SparseVector:
    def __init__(self, nums: List[int]):
        self.nums = {i: n for i, n in enumerate(nums) if n}

    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        if len(self.nums) < len(vec.nums):
            for key in self.nums.keys():
                if key in vec.nums:
                    result += self.nums[key] * vec.nums[key]
        else:
            for key in vec.nums.keys():
                if key in self.nums:
                    result += self.nums[key] * vec.nums[key]
                    
        return result

    '''
    Approach-2:
    Without HashMap
    FB interview accept this solution
    -Just going by the formula and without doing any prepocessing like whether elements are 0 or not
    TC:- O(n) for the result of calculating dot product or vector
    SC:- O(1) 
    '''
    class SparseVector:
        def __init__(self, nums):
            self.array = nums

        def dotProduct(self, vec):
            result = 0
            for num1, num2 in zip(self.array, vec.array):
                result += num1 * num2
            return result
     
'''
Approach-3:
Most Optimal Way
Tuple Solution
Its combination of Approach 1 + 2
We need to use Hash Map along with Tuple
When we are calculating dot product we would use two pointer 
TC:- O(N+M)
SC:- O(n)
'''
class Solution(object):
    def __init__(self,nums):
        self.nums = []
        for i,num in enumerate(nums):
            if num:
                self.nums.append((i,num))
    def dotProdut(Self,vec):
        DotProduct = 0
        i,j = 0,0
        while i<len(self.nums) and j<len(vec.nums):
            i_idx,i_num = self.nums[i]
            j_idx,j_num = vec.nums[j]
            if i_idx == j_idx:
                DotProduct += (i_num*j_num)
                i += 1
                j += 1
            elif i_idx > j_idx:
                j += 1
            else:
                i += 1
        return DotProduct
 '''
 Another Damn Follow-Up:-
 what would you do if one of the vectors werent fully "sparse" -> hint use binary search
 If the sizes of the two index-pair vectors are n and m then you iterate the smaller vector and binary search the larger one. 
 So the effective runtime is O(min(n, m) * log(max(n, m)))
 '''
'''
Approach-4:
Tuple + Binary Search
TC:- O(min(n,m)*log(max(n,m))
SC:- O(n+m)
'''
class SparseVector:
    def __init__(self, nums: List[int]):
        self.nums = []
        for i,num in enumerate(nums):
            if num:
                self.nums.append((i,num))
        ''''
        Write this only if interviewer ask about Binary - Search
        self.indices = []
        for idx in self.nums:
            self.indices.append(idx[0])
        '''

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        DotProduct = 0
        i,j = 0,0
        while i<len(self.nums) and j<len(vec.nums):
            i_idx,i_num = self.nums[i]
            j_idx,j_num = vec.nums[j]
            if i_idx == j_idx:
                DotProduct += (i_num*j_num)
                i += 1
                j += 1
            elif i_idx > j_idx:
                #j += 1
                #Advance j using binary search
                j = bisect.bisect_left(vec.indices, i_idx, lo=j+1)
            else:
                #i += 1
                # Advance i using binary search
                i = bisect.bisect_left(self.indices, j_idx, lo=i+1)
        return DotProduct
        

# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
     
