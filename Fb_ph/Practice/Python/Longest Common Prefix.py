'''
Approach-1:- Binary Search
TC:- O(S.log(m)) where S is the total number of characters for all strings in the given input string
SC:- O(1) we take constant space
'''
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def isCommonPrefix(strs, length):
        # has to put 0 in the strs index
            strl = strs[0][:length]
            print(strl)
            for i in range(1,len(strs)):
                if not strs[i].startswith(strl):
                    return False
            return True

        if not strs: return ""
        minLen = len(min(strs, key=len))
        low, high = 1, minLen
        # the binary search on the length of prefix on the first word
        while(low<=high):
            mid = (low+high) // 2
            if (isCommonPrefix(strs, mid)):
                low = mid + 1
            else:
                high = mid - 1
        return strs[0][:high]

'''
Approach:- LCP by Divide and Conquer
We can recursively divide the problem of finding LCP of an input array of words into 2 sub-problems of finding LCP on sub-components.
TC:- O(S) time where S is the total number of characters for all words in the array
SC:- O(Mlog(N)) space where N is the number of words in the array, 
M is the largest length of a word as we make log(N) recursive call and each call requires O(M) space
''''
def longestCommonPrefix(self, strs):
    def commonPrefix(left,right):
        min_len = min(len(left), len(right))
        for i in range(min_len):
            if left[i] != right[i]:
                return left[:i]
        return left[:min_len]

    def find_longestCommonPrefix(strs, left_index, right_index):
        if left_index == right_index:
            return strs[left_index]
        # recursive call
        else:
            mid_index = (left_index + right_index)//2
            lcpLeft = find_longestCommonPrefix(strs,left_index, mid_index)
            lcpRight = find_longestCommonPrefix(strs,mid_index+1,right_index)
            return commonPrefix(lcpLeft,lcpRight)

    if not strs: return ""
    return find_longestCommonPrefix(strs, 0, len(strs)-1)

'''
Approach:- Sorting
TC:- O(Slog(S)) where S is the total number of characters in inputString list
SC:- O(S) where S is the total number of characters in inputString list
'''
def longestCommonPrefix(self, strs):
    longest_pre = []
    if strs and len(strs) > 0:
        strs = sorted(strs)
        # e.g. before sort: ["flower","flow","flight","fake"]
        # after sort: ['fake', 'flight', 'flow', 'flower']
        first, last = strs[0], strs[-1]
        for i in range(len(first)):
            if len(last) > i and last[i] == first[i]:
                longest_pre.append(last[i])
            else:
                return "".join(longest_pre)
    return "".join(longest_pre)


'''
Approach:- Horizontal Scanning
TC:- O(S) where S is the total number of characters in input string list 
SC:- O(1)
'''
def longestCommonPrefix(self, strs):
    if not strs: return ""
    longest_pre = strs[0]
    for i in range(1,len(strs)):
        while(strs[i].find(longest_pre)!=0):
            longest_pre = longest_pre[:-1]
            if len(longest_pre) == 0: return ""
    return longest_pre

'''
Approach:- Vertical Scanning
TC:- O(S) where S is the total number of characters in input string list 
SC:- O(1)
'''
def longestCommonPrefix(self, strs):
    if not strs: return ""
    for i in range(len(strs[0])):
        char = strs[0][i]
        for j in range(1,len(strs)):
            if i == len(strs[j]) or strs[j][i] != char:
                return strs[0][:i]
    return strs[0]

'''
Approach:- Trie
TC:- O(S) where S is the total number of characters of all words in string
SC:- O(S) as we require extra space for the creation of Trie
'''
class TrieNode:
    def __init__(self):
        self.children = dict()
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current = self.root

        for ch in word:
            if ch not in current.children:
                current.children[ch] = TrieNode()
            current = current.children[ch]

        current.is_end_of_word = True

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs: return ""

        trie = Trie()

        for word in strs:
            trie.insert(word)

        prefix = ""
        current = trie.root

        while len(current.children) == 1 and not current.is_end_of_word:
            ch = next(iter(current.children))
            prefix += ch
            current = current.children[ch]
        
        return prefix
