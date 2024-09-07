'''
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

'''
'''
Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
'''


class TrieNode:
    def __init__(self):
        self.is_word = False
        self.child = dict()
        
class Trie:
    def __init__(self, words):
        self.words = words
        self.root = TrieNode()
        self.build_trie()
        
    def build_trie(self):    
        for word in self.words:
            self.add_word(word)
    
    def add_word(self, word):
        root = self.root
        for c in word:
            if c not in root.child:
                root.child[c] = TrieNode()
            root = root.child[c]
        
        root.is_word = True
        
    # def seach_word(self, word):
    #     root = self.root
    #     for c in word:
    #         if c not in root:
    #             return False
    #         root = root.child[c]
    #     return root.is_child
        
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        use trie to search the word
        
        TC: build trie + search in board
        
              O(NL) + O(mn(4^L)) 
              N = len(words), L = max length of word, m = len(board), n = len(board[0])
        """
        
        def dfs(r, c, root, part):
            if root.is_word:
                ans.append(part)
                
                # tricky part
                # prevet duplicate word found in board
                root.is_word = False
                
                # don't return for search word with prefix part string
                # return
            
            letter = board[r][c]
            board[r][c] = None
            for dx, dy in dirs:
                x, y = r + dx, c + dy
                if 0 <= x < m and 0 <= y < n and board[x][y] in root.child:
                    dfs(x, y, root.child[board[x][y]], part + board[x][y])
                
            board[r][c] = letter
            
        
        word_trie = Trie(words)
        word_root = word_trie.root
        ans = []
        dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        m, n = len(board), len(board[0])
        for r in range(m):
            for c in range(n):
                if board[r][c] in word_root.child:
                    dfs(r, c, word_root.child[board[r][c]], board[r][c])
        return ans
