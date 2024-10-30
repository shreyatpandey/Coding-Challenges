'''
Can you break the given string into words, provided by a given hashmap of frequency of word as <word: n>

Example 1:
HashMap -> {"abc":3, "ab":2, "abca":1}
String: "abcabcabcabca"
Output: true
Explanation: "abc" + "abc" + "abc" + "abca"

Example 2:
HashMap -> {"abc":3, "ab":2}
String: "abcabab"
Output: true
Explanation: "abc" + "ab" + "ab"
'''
'''
TC :- O(n^3)
SC :- O(n) for recursion stack
'''
def word_break(word, map):
    if len(word) == 0:  # base case
        return True
    i = 1
    while i <= len(word):
        #  we divide the current word in 2: from 0...i and i...end. Check that the first half is in the map AND it has frequency available
        if word[:i] in map and map[word[:i]] > 0:
            map[word[:i]] -= 1  # reduce the frequency and try again with the second half of the word (word break)
            if word_break(word[i:], map):
                return True
            map[word[:i]] += 1  # if it wasn't possible, update frequency and keep with the loop, trying with a different word break
        i += 1
    return False

if __name__ == '__main__':
    print("Test-Case-1")
    map = {"abc":3, "ab":2, "abca":1}
    word = "abcabcabcabca"
    print(word_break(word, map))
