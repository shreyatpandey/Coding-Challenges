'''
Given a string s, find the minimum number of substrings you can create without having the same letters repeating in each substring.
E.g world -> 5, as the string has no letters that occur more than once.
dddd -> 4, as you can only create substring of each character.
abba -> 2, as you can make substrings of ab, ba.
cycle-> 2, you can create substrings of (cy, cle) or (c, ycle)
'''

def minNoOfSubstr(string):
    minSubstr = 1
    stringBuild = ""
    for char in string:
        if char in stringBuild:
            minSubstr += 1
            stringBuild = char
        else:
            stringBuild += char
    return minSubstr
  
result = minNoOfSubstr("world")
print("result:",result)
result = minNoOfSubstr("dddd")
print("result:",result)
result = minNoOfSubstr("abba")
print("result:",result)
