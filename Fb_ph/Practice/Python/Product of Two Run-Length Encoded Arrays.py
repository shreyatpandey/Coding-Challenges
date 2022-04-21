'''
Wording:-
Run-length encoding is a compression algorithm that allows for an integer array nums with many segments of consecutive repeated numbers to be represented by a (generally smaller) 2D array encoded. Each encoded[i] = [vali, freqi] describes the ith segment of repeated numbers in nums where vali is the value that is repeated freqi times.

For example, nums = [1,1,1,2,2,2,2,2] is represented by the run-length encoded array encoded = [[1,3],[2,5]]. 
Another way to read this is "three 1's followed by five 2's".
The product of two run-length encoded arrays encoded1 and encoded2 can be calculated using the following steps:

Expand both encoded1 and encoded2 into the full arrays nums1 and nums2 respectively.
Create a new array prodNums of length nums1.length and set prodNums[i] = nums1[i] * nums2[i].
Compress prodNums into a run-length encoded array and return it.
You are given two run-length encoded arrays encoded1 and encoded2 representing full arrays nums1 and nums2 respectively. 
Both nums1 and nums2 have the same length. Each encoded1[i] = [vali, freqi] 
describes the ith segment of nums1, and each encoded2[j] = [valj, freqj] describes the jth segment of nums2.

Return the product of encoded1 and encoded2.
'''
'''
Constraints:-
1 <= encoded1.length, encoded2.length <= 105
encoded1[i].length == 2
encoded2[j].length == 2
1 <= vali, freqi <= 104 for each encoded1[i].
1 <= valj, freqj <= 104 for each encoded2[j].
The full arrays that encoded1 and encoded2 represent are the same length.
'''
'''
Wording:-
Simple-Straight Forward Solution
Expand result for encoded1 (O(10^5) * O(10^4) = O(10^9))
Expand result for encoded2
Calculate product of two results
Use two pointer to get the final result

Optimized Soltuon:-
A better solution, instead of expanding the encoded arrays, we can
Take 2 points on each array
Each iteration, take the shorter frequency, calculate product and add to ans
Deduct current frequency by the smaller frequency (since it's used), and increment pointers i or j when current frequency is empty
Also, handle the situation where current product is same as the previous product and update the frequency accordingly

'''
'''
Complexity:-
TC:- O(m+n)
where m is the len(encoded1) and n is the len(encoded2)
SC:- O(1)
Not counting the space of the final result

'''
class Solution(object):
    def findRLEArray(self, encoded1, encoded2):
        """
        :type encoded1: List[List[int]]
        :type encoded2: List[List[int]]
        :rtype: List[List[int]]
        """
        product_encoded = []
        e1_index = 0
        e2_index = 0

        while e1_index < len(encoded1) and e2_index < len(encoded2):
            e1_val, e1_freq = encoded1[e1_index]
            e2_val, e2_freq = encoded2[e2_index]

            product_val = e1_val * e2_val
            product_freq = min(e1_freq, e2_freq)

            encoded1[e1_index][1] -= product_freq
            encoded2[e2_index][1] -= product_freq

            if encoded1[e1_index][1] == 0:
                e1_index += 1

            if encoded2[e2_index][1] == 0:
                e2_index += 1

            if not product_encoded or product_encoded[-1][0] != product_val:
                product_encoded.append([product_val, product_freq])
            else:
                product_encoded[-1][1] += product_freq



        return product_encoded
        