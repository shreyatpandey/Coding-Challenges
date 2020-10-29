class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        list_intersect_array = []
        length_nums1 = len(nums1)
        length_nums2 = len(nums2)
        dict_number = {}
        number = 0
        if length_nums1 > length_nums2:
            for i in range(0,length_nums2):
                if nums2[i] in dict_number:
                    dict_number[nums2[i]] += 1
                else:
                    dict_number[nums2[i]] = 1
            for (key,values) in dict_number.items():
                if key in nums1:
                    indices = [i for i, x in enumerate(nums1) if x == key]
                    min_values = min(len(indices),values)
                    for j in range(0,min_values):
                        list_intersect_array.append(key)
        else:
            for i in range(0,length_nums1):
                if nums1[i] in dict_number:
                    dict_number[nums1[i]] += 1
                else:
                    dict_number[nums1[i]] = 1
            for (key,values) in dict_number.items():
                if key in nums2:
                    indices = [i for i, x in enumerate(nums2) if x == key]
                    min_values = min(len(indices),values)
                    for j in range(0,min_values):
                        list_intersect_array.append(key)
           
        
        return list_intersect_array

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for i in nums1:
            if i in nums2:
                x.append(i)
                nums2.remove(i)
        return x

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dic = {}
        for i in nums1:
            if i not in dic:
                dic[i] = 1
            else:
                dic[i] += 1

        res = []
        for j in nums2:
            if (j in dic) and (dic[j] > 0):
                res.append(j)
                dic[j] -= 1
        return res
