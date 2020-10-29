class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)-1
        length_list = len(nums)
        while low < high :
            mid = low + (high-low)//2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        
        pivot_element = low
        low = 0
        high = len(nums) - 1
        
        while low <= high :
            mid = low + (high-low)//2
            rotated_element = (pivot_element + mid)%length_list
            if nums[rotated_element] == target :
                return rotated_element
            elif nums[rotated_element] < target :
                low = mid + 1
            else:
                high = mid - 1
        return -1
        
