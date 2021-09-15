'''
Write a function that, given an array A of N integers, returns the lagest integer K > 0 such that both values K and -K exist in array A.
If there is no such integer, the function should return 0.
'''
'''
TC:- O(n)
SC:- O(n)
'''

def FindLargetKWithMinusK(nums):
    Map={}
    largestNo = float('-inf')
    for i in nums:
        if abs(i) in Map:
            largestNo = max(largestNo,abs(i))
        else:
            Map[i] = str(i)
    print("Map:",Map)
    if largestNo == float('-inf'):
        return 0
    return largestNo

def FindLargestKWithMinusK2(nums):
    hashSet = set()
    largestNo = float('-inf')
    for i in nums:
        hashSet.add(i)
        if -i in hashSet :
            largestNo = max(largestNo,-i)
    if largestNo == float('-inf'):
        return 0
    return largestNo

'''
TC:- O(log(n))
SC:- O(1)
'''
def FindLargestKWithMinusK3(nums):
    l,r = 0,len(nums)-1
    nums.sort()
    largestNo = 0
    while l < r :
        Sum = nums[l] + nums[r]
        if nums[l] + nums[r] == 0:
            largestNo = max(largestNo,nums[r])
            l += 1
            r -=1
        elif Sum < 0 :
            l += 1
        else:
            r -= 1
    return largestNo
 
result = FindLargetKWithMinusK([3, 2, -2, 5, -3])
print("result:",result)
result = FindLargetKWithMinusK([1, 2, 3, -4])
print("result:",result)
result = FindLargetKWithMinusK([10,-10,100,-90,-100])
print("result:",result)

print("=====|End Of Fun1 Testing|=====")

result = FindLargestKWithMinusK2([3, 2, -2, 5, -3])
print("result:",result)
result = FindLargestKWithMinusK2([1, 2, 3, -4])
print("result:",result)
result = FindLargestKWithMinusK2([10,-10,100,-90,-100])
print("result:",result)

print("=====|End Of Fun2 Testing|=====")


result = FindLargestKWithMinusK3([3, 2, -2, 5, -3])
print("result:",result)
result = FindLargestKWithMinusK3([1, 2, 3, -4])
print("result:",result)
result = FindLargestKWithMinusK3([10,-10,100,-90,-100])
print("result:",result)
