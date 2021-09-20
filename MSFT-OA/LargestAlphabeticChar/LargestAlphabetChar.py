def largeAlphaChar(inputString):
    if len(inputString) == 0:
        return 0
    hashMap = {}
    for char in inputString: #o(n)
        if char.islower():
            if char not in hashMap:
                hashMap[char] = char.upper()
    charInput = 'A'
    for key,values in hashMap.items():
        if values in inputString and values > charInput: #O(n^2)
            charInput = values
    return charInput
  
  
result = largeAlphaChar("admeDCAB")
print("result:",result)
result = largeAlphaChar("DdcCamEe")
print("result:",result)
