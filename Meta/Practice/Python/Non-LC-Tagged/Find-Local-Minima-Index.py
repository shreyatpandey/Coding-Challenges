'''
Return any local minima index in an array. Eg. [2, 7, 5, 8, 9] You can return either 0 or 2.
'''
'''
Let N be the length of input array/list
TC :- O(Log(N))
SC :- O(1)
'''
def localMinima(nums):
    l, r = 0, len(nums)-1
    if nums[0] > nums[1] :
        return 0
    
    while l < r:
        m = (l+r) // 2
        if nums[m] > nums[m + 1]: # '>' compared to peak element
            l = m + 1
        else:
            r = m
    return l

if __name__ == '__main__' :
    inputList = [2,7,5,8,9]
    print(localMinima(inputList))

    inputList = [6,7,5,1,8,9]
    print(localMinima(inputList))