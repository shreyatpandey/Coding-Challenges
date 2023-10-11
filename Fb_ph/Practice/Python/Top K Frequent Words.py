'''
Approach:- Min Heap
Tc:- O(N*log(k)) 
where N is the length of words
We count the frequency of each word in O(N) time, then we add N words to the heap
each in O(log(k)) time
Sc:- O(N) for counter and O(k) for heap space


'''
from collections import Counter
from heapq import heappush, heappop

class Pair:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq

    def __lt__(self, p):
        return self.freq < p.freq or (self.freq == p.freq and self.word > p.word)


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = Counter(words)
        h = []
        for word, freq in cnt.items():
            heappush(h, Pair(word, freq))
            if len(h) > k:
                heappop(h)
        return [p.word for p in sorted(h, reverse=True)]


'''
Approach:- Bucket sorting + Trie
Tc:- O(N)
Sc:- O(N)
'''

from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        n = len(words)
        cnt = Counter(words)
        bucket = [{} for _ in range(n+1)]
        self.k = k

        def add_word(trie: Mapping, word: str) -> None:
            root = trie
            for c in word:
                if c not in root:
                    root[c] = {}
                root = root[c]
            root['#'] = {}

        def get_words(trie: Mapping, prefix: str) -> List[str]:
            if self.k == 0:
                return []
            res = []
            if '#' in trie:
                self.k -= 1
                res.append(prefix)
            for i in range(26):
                c = chr(ord('a') + i)
                if c in trie:
                    res += get_words(trie[c], prefix+c)
            return res

        for word, freq in cnt.items():
            add_word(bucket[freq], word)

        res = []
        for i in range(n, 0, -1):
            if self.k == 0:
                return res
            if bucket[i]:
                res += get_words(bucket[i], '')
        return res
  
  '''
  Quick-Select may not work in this case as the output needs to be lexicographically be sorted
  '''
'''
If the output need not be lexicograhically sorted
Tc:- O(n) best case, O(n^2) in worst case
Sc:- O(1)
'''
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counts_dict = Counter(words)
        counts = list(counts_dict.items())
        
        n = len(counts)
        
        # since we are sorting in ASC order, the kth most frequent element is the (n - k)th element
        self.quickselect(0, n - 1, n - k, counts)
        return [count[0] for count in counts[n - k:]]
     
    def partition(self, left: int, right: int, counts: list[tuple[int, int]]):
        # get random pivot index
        pivot_index = random.randint(left, right)  
        pivot_value = counts[pivot_index][1]
        # move pivot element to the end
        counts[pivot_index], counts[right] = counts[right], counts[pivot_index]
        # when we find an element less than pivot_value, move it left of pivot_index and increment the swap position
        i = left
        for j in range(left, right):
            if counts[j][1] < pivot_value:
                counts[i], counts[j] = counts[j], counts[i]
                i += 1
        # move pivot to its final place
        counts[right], counts[i] = counts[i], counts[right]
        return i
        
    def quickselect(self, left: int, right: int, k_target_index: int, counts: list[tuple[int, int]]):
        # base case: if there is only one element in the partition, it's already sorted
        if left == right:
            return
        # find the pivot's correct position
        pivot_index = self.partition(left, right, counts)
        # if the pivot index is equal to our target, we're done
        if k_target_index == pivot_index:
            return
        elif k_target_index < pivot_index:
            self.quickselect(left, pivot_index - 1, k_target_index, counts)
        else:
            self.quickselect(pivot_index + 1, right, k_target_index, counts)

