# Meta Top Frequently asked Questions

Leetcode Premium Meta Questions which I have not done it yet
| Question | Link | Input |
| :---: | :---: | :---: |
| Print Immutable Linked List in Reverse | https://leetcode.com/problems/print-immutable-linked-list-in-reverse/description/| ImmutableListNode: An interface of immutable linked list, you are given the head of the list<br>Example 1:Input: head = [1,2,3,4]<br>Output: [4,3,2,1]<br>|
| Find Distance in a Binary Tree | https://leetcode.com/problems/find-distance-in-a-binary-tree/description/| Input: root [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0<br>Output: 3<br>Explanation: There are 3 edges between 5 and 0: 5-3-1-0|
| Count Nodes Equal to Sum of Descendants | https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/ | Input: root = [10,3,4,2,1]<br>Output: 2<br>Explanation: For the node with value 10: The sum of its descendants is 3+4+2+1 = 10<br>For the node with value 3: The sum of its descendants is 2+1 = 3<br>|
| Shortest Way To Form a String|https://leetcode.com/problems/shortest-way-to-form-string/description/| Input: source = "abc"<br>target = "abcbc"<br>Output: 2<br>Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc"|
|Encode and Decode Strings| https://leetcode.com/problems/encode-and-decode-strings/description/|Input: dummy_input = ["Hello","World"]<br>Output: ["Hello","World"]<br>Explanation: Machine 1: Codec encoder = new Codec();<br>String msg = encoder.encode(strs);<br>Machine 1 ---msg---> Machine 2<br>Machine 2:<br>Codec decoder = new Codec();<br>String[] strs = decoder.decode(msg);|
| Best Meeting Point| https://leetcode.com/problems/best-meeting-point/description/ | Input: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]<br>Output: 6<br>Explanation: Given three friends living at (0,0), (0,4), and (2,2).<br>The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.<br>So return 6.|
| Two Sum Less Than K|https://leetcode.com/problems/two-sum-less-than-k/description/|Input: nums = [34,23,1,24,75,33,54,8], k = 60<br>Output: 58<br>Explanation: We can use 34 and 24 to sum 58 which is less than 60.|
| Employee Free Time|https://leetcode.com/problems/employee-free-time/description/|Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]<br>Output: [[3,4]]<br>Explanation: There are a total of three employees, and all common<br>free time intervals would be [-inf, 1], [3, 4], [10, inf].<br>We discard any intervals that contain inf as they aren't finite.|
|First Unique Number|https://leetcode.com/problems/first-unique-number/description/|Input<br>["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]<br>[[[2,3,5]],[],[5],[],[2],[],[3],[]]<br>Output: [null,2,null,2,null,3,null,-1]|
| Tree Diameter|https://leetcode.com/problems/tree-diameter/description/|Input: edges = [[0,1],[0,2]]<br>Output: 2<br>Explanation: The longest path of the tree is the path 1 - 0 - 2.|
| Palindrome Permutation 2|https://leetcode.com/problems/palindrome-permutation-ii/description/|Input: s = "aabb"<br>Output: ["abba","baab"]|
| Design A Leaderboard | https://leetcode.com/problems/design-a-leaderboard/description/ | Input:["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]<br>[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]<br>Output: [null,null,null,null,null,null,73,null,null,null,141] |
| All Elements in Two Binary Search Trees | https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/ | Input: root1 = [2,1,4], root2 = [1,0,3]<br>Output: [0,1,1,2,3,4] |




Questions With Series<br>
**Word Search**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---:|
| Word Search | https://leetcode.com/problems/word-search/description/|Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"<br>|Output: true DFS<br>Directions<br>Consruction Of String|
| Word Search II| https://leetcode.com/problems/word-search-ii/description/| Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"["i","f","l","v"]], words = ["oath","pea","eat","rain"]<br> Output: ["eat","oath"] | Trie<br>Add word in Trie<br>DFS<br>|

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






