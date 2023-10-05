# Meta Top Frequently asked Questions

Leetcode Premium Meta Questions which I have not done it yet
| Question | Link | Input |
| :---: | :---: | :---: |
| Print Immutable Linked List in Reverse | https://leetcode.com/problems/print-immutable-linked-list-in-reverse/description/| ImmutableListNode: An interface of immutable linked list, you are given the head of the list<br>Example 1:Input: head = [1,2,3,4]<br>Output: [4,3,2,1]<br>|
| Find Distance in a Binary Tree | https://leetcode.com/problems/find-distance-in-a-binary-tree/description/| Input: root [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0<br>Output: 3<br>Explanation: There are 3 edges between 5 and 0: 5-3-1-0|
| Count Nodes Equal to Sum of Descendants | https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/ | Input: root = [10,3,4,2,1]<br>Output: 2<br>Explanation: For the node with value 10: The sum of its descendants is 3+4+2+1 = 10<br>For the node with value 3: The sum of its descendants is 2+1 = 3<br>|
| Shortest Way To Form a String|https://leetcode.com/problems/shortest-way-to-form-string/description/| Input: source = "abc"<br>target = "abcbc"<br>Output: 2<br>Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc"|
|Encode and Decode Strings| https://leetcode.com/problems/encode-and-decode-strings/description/|Input: dummy_input = ["Hello","World"]<br>Output: ["Hello","World"]<br>Explanation: Machine 1: Codec encoder = new Codec();<br>String msg = encoder.encode(strs);<br>Machine 1 ---msg---> Machine 2<br>
Machine 2:<br>Codec decoder = new Codec();<br>String[] strs = decoder.decode(msg);|
| Best Meeting Point| https://leetcode.com/problems/best-meeting-point/description/ | Input: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]<br>Output: 6
Explanation: Given three friends living at (0,0), (0,4), and (2,2).<br>The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.<br>So return 6.|



Questions With Series<br>
**Word Search**<br>
| Question | Link | Concept Involved |
| :---:   | :---: | :---: |
| Word Search | https://leetcode.com/problems/word-search/description/| DFS<br>Directions<br>Consruction Of String|
| Word Search II| https://leetcode.com/problems/word-search-ii/description/| Trie<br>Add word in Trie<br>DFS<br>|

**Word Break**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---:|
| Word Break | https://leetcode.com/problems/word-break/description/ | Input: s = "leetcode"<br>wordDict = ["leet","code"]<br>Output: true<br>|  BFS<br>DFS<br>Dynamic Programming|
| Word Break II| https://leetcode.com/problems/word-break-ii/description/ | Input: s = "catsanddog"<br>wordDict = ["cat","cats","and","sand","dog<br>Output: ["cats and dog","cat sand dog"]<br>| Recursion With Memoization<br>|

**Word Ladder**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---: |
| Word Ladder | https://leetcode.com/problems/word-ladder/description/ | Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"] <br> Output: 5 <br>Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.<br> | Remaining |

**String Counter**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---: |
| Custom Sort String | https://leetcode.com/problems/custom-sort-string/description/ | Input: order = "cbafg",<br>s = "abcd"<br>Output: "cbad"| Frequency Counter of string<br>Check the frequency in another string<br>|
| Ransom Note|https://leetcode.com/problems/ransom-note/description/|Input: ransomNote = "aa",<br>magazine = "ab"<br>Output: false| Frequency Counter of string<br>|

**Inorder Successor of BST**
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---: |
| Inorder Successor of BST-I|https://leetcode.com/problems/inorder-successor-in-bst/description/|Input: root = [2,1,3]<br>p = 1<br>Output: 2<br>Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type| Iterative|
| Inorder Successor of BST-II | https://leetcode.com/problems/inorder-successor-in-bst-ii/description/| Input: tree = [2,1,3]<br>node = 1<br>Output: 2<br>Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type<br>| Node has access to parent pointer<br>|






