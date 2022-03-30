'''
You are given a string s and an array of strings words. 
You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words.
If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. 
If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.

'''
'''
Input:-Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
'''
'''
TC:- O(m.n) 
where m is the longest word
n is the total number of words

SC:-
O(MN) trie construction
O(N) for final string Construction
O(MN + N)

'''
class Solution:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        trie, n, intervals, res = {}, len(s), [], ""

        # create trie tree
        for w in words:
            cur = trie
            for c in w:
                cur = cur.setdefault(c, {})
            cur["#"] = 1

        # interval merge
        def add_interval(interval):
            if intervals and intervals[-1][1] >= interval[0]:
                if intervals[-1][1] < interval[1]:
                    intervals[-1][1] = interval[1]
            else:
                intervals.append(interval)

        # make max match and add to interval
        for i in range(n):
            cur, max_end = trie, None
            for j in range(i, n):
                if s[j] not in cur:
                    break
                cur = cur[s[j]]
                if "#" in cur:
                    max_end = j + 1
            # just need to add max-match interval
            if max_end:
                add_interval([i, max_end])

        # concat result
        res, prev_end = "", 0
        for start, end in intervals:
            res += s[prev_end:start] + '<b>' + s[start:end] + "</b>"
            prev_end = end
        return res + s[prev_end:]
