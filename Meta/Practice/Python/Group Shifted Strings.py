'''
We can shift a string by shifting each of its letters to its successive letter.
For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.
For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

'''
'''
Example 1:

Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
'''

'''
Complexity-analysis
TC:- O(NM) where N is the length of list of string and M is the length of each string
SC:- O(N) where N is the space required for hashmap
'''

'''
Constraints:
1 <= strings.length <= 200
1 <= strings[i].length <= 50
strings[i] consists of lowercase English letters.
'''

'''
Approach:-
We need to watch out for the "wraparound" case - for example, 
'az' and 'ba' should map to the same "shift group" as a + 1 = b and z + 1 = a. 
Given the above point, the respective tuples would be (25,) (122 - 97) and (-1,) (79 - 80) 
and az and ba would map to different groups. This is incorrect.
To account for this case, we add 26 to the difference between letters (smallest difference possible is -25, za) 
and mod by 26. So, (26 + 122 - 97) % 26 and (26 + 79 - 80) % 26 both equal
'''
from collections import defaultdict
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)
        for s in strings:
            key = []
            for i in range(len(s) - 1):
                # Throw in 26 so that we can normalzie below
                difference = 26 + ord(s[i+1]) - ord(s[i])
                # Wrap around
                # z + 1 = a
                key.append(str(difference % 26))
            hashmap[','.join(key)].append(s)
        return list(hashmap.values())
