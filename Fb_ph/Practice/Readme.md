# Meta Top Frequently asked Questions

**Leetcode Premium Meta Questions which I have not done it yet as well as done some of them**<br>
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
| Palindrome Permutation | https://leetcode.com/problems/palindrome-permutation/description/ | Given a string s, return true if a permutation of<br> thestring could form a palindrome and false otherwise.Example 1:Input: s = "code"Output: false|
| Palindrome Permutation 2|https://leetcode.com/problems/palindrome-permutation-ii/description/|Input: s = "aabb"<br>Output: ["abba","baab"]|
| Design A Leaderboard | https://leetcode.com/problems/design-a-leaderboard/description/ | Input:["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]<br>[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]<br>Output: [null,null,null,null,null,null,73,null,null,null,141] |
| All Elements in Two Binary Search Trees | https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/ | Input: root1 = [2,1,4], root2 = [1,0,3]<br>Output: [0,1,1,2,3,4] |
| Boundary of Binary Tree | https://leetcode.com/problems/boundary-of-binary-tree/description/ | Input: root = [1,null,2,3,4]<br>Output: [1,3,4,2]<br>Explanation:- The left boundary is empty because the root does not have a left child.<br>- The right boundary follows the path starting from the root's right child 2 -> 4.<br>4 is a leaf, so the right boundary is [2].<br>- The leaves from left to right are [3,4].<br>Concatenating everything results in [1] + [] + [3,4] + [2] = [1,3,4,2]. |
| Binary Tree Longest Consecutive Sequence | https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/ | Input: root = [1,null,3,2,4,null,null,null,5]<br>Output: 3<br>Explanation: Longest consecutive sequence path is 3-4-5, so return 3.|
| Largest BST Subtree | https://leetcode.com/problems/largest-bst-subtree/description/ | Input: root = [10,5,15,1,8,null,7]<br>Output: 3<br>Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.|
| Add Bold Tag in String | https://leetcode.com/problems/add-bold-tag-in-string/description/ |Example 1:Input: s = "abcxyz123",words = ["abc","123"]<br>Output: **"<b>abc</b>xyz<b>123</b>"**<br>Explanation: The two strings of words are substrings of s as following: "abcxyz123".We add <b> before each<br>substring and </b> after each substring.|
| Leftmost Column With at Least One | https://leetcode.com/problems/leftmost-column-with-at-least-a-one/description/ | Given a row-sorted<br>binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist,return -1.|

**Hard - Level Problems**<br>
| Question | Link | Input |
| :---: | :---: | :---: |
| Text Justification | https://leetcode.com/problems/text-justification/description/ | Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16<br>Output:<br>[ "This    is    an", "example  of text", "justification.  "]
| Sum-of-k-mirror-numbers [ One killer of a question]| https://leetcode.com/problems/sum-of-k-mirror-numbers/description/ | Input: k = 2, n = 5 <br>Output: 25<br>Explanation:<br>The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows: 1<br>Their sum = 1 + 3 + 5 + 7 + 9 = 25.|
| Reconstruct Itinerary | https://leetcode.com/problems/reconstruct-itinerary/description/ | Input: tickets = [["MUC","LHR"],["JFK","MUC"]<br>["SFO","SJC"],["LHR","SFO"]]<br> Output: ["JFK","MUC","LHR","SFO","SJC"] |


        




**All Word Problems**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---:|
| Word Search | https://leetcode.com/problems/word-search/description/|Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"<br>|Output: true DFS<br>Directions<br>Consruction Of String|
| Word Search II| https://leetcode.com/problems/word-search-ii/description/| Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"["i","f","l","v"]], words = ["oath","pea","eat","rain"]<br> Output: ["eat","oath"] | Trie<br>Add word in Trie<br>DFS<br>|
| Word Break | https://leetcode.com/problems/word-break/description/ | Input: s = "leetcode"<br>wordDict = ["leet","code"]<br>Output: true<br>|  BFS<br>DFS<br>Dynamic Programming|
| Word Break II| https://leetcode.com/problems/word-break-ii/description/ | Input: s = "catsanddog"<br>wordDict = ["cat","cats","and","sand","dog<br>Output: ["cats and dog","cat sand dog"]<br>| Recursion With Memoization<br>|
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

**Morrison Traversal**<br>
| Question | Link | Answer Link |
| :---:   | :---: | :---: |
| Binary Tree Inorder Traversal | https://leetcode.com/problems/binary-tree-inorder-traversal/editorial/|
| Binary Search Tree Iterator |  https://leetcode.com/problems/binary-search-tree-iterator/description/ | https://leetcode.com/problems/binary-search-tree-iterator/solutions/52520/python-o1-space-and-o1-time-morris-inorder-traversal/ 
| Binary Tree Preorder Traversal | https://leetcode.com/problems/binary-tree-preorder-traversal/description/ |
| Sum Root to Leaf Numbers | https://leetcode.com/problems/sum-root-to-leaf-numbers/description/ | 

**Longest Sequences**<br>
Difference between consecutive and continuous is for consecutive, nums[i+1] = nums[i] + 1<br> 
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---: |
| Longest Continuous Increasing Subsequence | https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/ | Input: nums = [1,3,5,4,7]<br>Output: 3<br>Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.<br>Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element4.| Sliding Window
| Longest Increasing Subsequence | https://leetcode.com/problems/longest-increasing-subsequence/description/ | Input: nums = [10,9,2,5,3,7,101,18]<br>Output: 4<br>Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.| https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/
| Longest Consecutive Sequence | https://leetcode.com/problems/longest-consecutive-sequence/description/ | Example 1: Input: nums = [100,4,200,1,3,2]<br>Output: 4<br>Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.| O(n) time 

**Path Sum Series**<br>
| Question | Link | Input | Concept Involved |
| :---:   | :---: | :---: | :---: |
| Path Sum | https://leetcode.com/problems/path-sum/description/ | Input: root = [1,2,3], targetSum = 5<br>Output: false<br>Explanation: There two root-to-leaf paths in the tree:<br>(1 --> 2): The sum is 3.<br>(1 --> 3): The sum is 4.<br>There is no root-to-leaf path with sum = 5.|
| Path Sum II | https://leetcode.com/problems/path-sum-ii/description/ | Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22<br>Output: [[5,4,11,2],[5,8,4,5]]<br>Explanation: There are two paths whose sum equals targetSum:<br>5 + 4 + 11 + 2 = 22<br>5 + 8 + 4 + 5 = 22 | Only DFS , don't use BFS
| Path Sum III | https://leetcode.com/problems/path-sum-iii/description/| Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22<br>Output: 3 |
| Path Sum IV | https://leetcode.com/problems/path-sum-iv/description/ | Input: nums = [113,215,221]<br>Output: 12<br>Explanation: The tree that the list represents is shown.<br>The path sum is (3 + 5) + (3 + 1) = 12.|
| Sum Root to Leaf Numbers | https://leetcode.com/problems/sum-root-to-leaf-numbers/description/ | Input: root = [1,2,3]<br>Output: 25<br>Explanation:<br>The root-to-leaf path 1->2 represents the number 12.<br>The root-to-leaf path 1->3 represents the number 13.<br>Therefore, sum = 12 + 13 = 25.|
| Binary Tree Maximum Path | https://leetcode.com/problems/binary-tree-maximum-path-sum/description/ | Input: root = [-10,9,20,null,null,15,7]<br>Output: 42<br>Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42. |

**Manhattan Distance**<br>
| Question | Link | Input |
| :---:   | :---: | :---: |
| Shortest Distance from All Buildings | https://leetcode.com/problems/shortest-distance-from-all-buildings/description/ | Input: grid =[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]<br>Output: 7<br>Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).<br>The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.<br>So return 7.|
| Best Meeting Point |

**Bricks and Walls Type**<br>
| Question | Link | Input |
| :---:   | :---: | :---: |
| The Maze | https://leetcode.com/problems/the-maze/ | Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4],destination = [4,4]<br>Output: true<br>Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.|
| Walls and Gates | https://leetcode.com/problems/walls-and-gates/description/ | -1 A wall or an obstacle.<br>0 A gate.<br> INF Infinity means an empty room. Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]<br>Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]] |

**Missing Number**<br>
| Question | Link | Input | Sorted or Unsorted
| :---:   | :---: | :---: | :---: |
| Find all Numbers Disappeared in an Array| https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/ | Input: nums =[4,3,2,7,8,2,3,1]<br>Output: [5,6]| Unsorted | 
| First Missing Positive | https://leetcode.com/problems/first-missing-positive/description/ | Input: nums = [3,4,-1,1]<br>Output: 2<br>Explanation: 1 is in the array but 2 is missing.| Unsorted | 
| Missing Number | https://leetcode.com/problems/missing-number/description/ | Input: nums = [3,0,1]<br>Output: 2<br>Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.| Unsorted |
| Missing Element in Sorted Array | https://leetcode.com/problems/missing-element-in-sorted-array/description/ | Input: nums = [4,7,9,10], k = 1<br> Output: 5<br>Explanation: The first missing number is 5.| Sorted |
| Missing Ranges | https://leetcode.com/problems/missing-ranges/description/ | Input: nums = [0,1,3,50,75], lower = 0, upper = 99<rb>Output: [[2,2],[4,49],[51,74],[76,99]]<br>Explanation: The ranges are:<br>[2,2][4,49][51,74][76,99] | Sorted

**Distance**<br>
| Question | Link | Input |
| :---:   | :---: | :---: |
| Edit Distance | https://leetcode.com/problems/edit-distance/description/| You have the following three operations permitted on a word:<br>Insert a character , Delete a character, Replace a character<br>Input: word1 = "horse", word2 = "ros" , Output: 3 , Explanation: horse -> rorse (replace 'h' with 'r'),rorse -> rose (remove 'r'), rose -> ros (remove 'e')|
| One Edit Distance | https://leetcode.com/problems/one-edit-distance/description/ | A string s is said to be one distance apart from a string t if you can:Insert exactly one character into s to get t , Delete exactly one character from s to get t , Replace exactly one character of s with a different character to get t.<br>Input: s = "ab", t = "acb" , Output: true , Explanation: We can insert 'c' into s to get t.|

**Peak Index Series**<br>
| Question | Link | Input |
| :---:   | :---: | :---: |
| Find Peak Element | https://leetcode.com/problems/find-peak-element/description/ | Input: nums = [1,2,3,1], Output: 2<br>Explanation: 3 is a peak element and your function should return the index number 2.|
| Peak Index in a Mountain Array | https://leetcode.com/problems/peak-index-in-a-mountain-array/description/ | Input: arr = [0,10,5,2],Output: 10|
| Find in Mountain Array | https://leetcode.com/problems/find-in-mountain-array/description/ | Input: array = [1,2,3,4,5,3,1], target = 3,Output: 2<br>Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.|

**Substring**<br>
| Question | Link | Input |
| :---:   | :---: | :---: |
| Longest Substring without Repeating Characters | https://leetcode.com/problems/longest-substring-without-repeating-characters/description/|Input:s = "abcabcbb"<br>Output: 3<br>Explanation: The answer is "abc", with the length of 3.|
| Longest Repeating Character Replacement| https://leetcode.com/problems/longest-repeating-character-replacement/description/ | Input: s = "ABAB", k = 2<br>Output: 4<br>Explanation: Replace the two 'A's with two 'B's or vice versa.|

**Water Questions**<br>
| Question | Link | Input
| :---:   | :---: | :---: |
| Container With Most Water | https://leetcode.com/problems/container-with-most-water/description/ | Return the maximum amount of water a container can store.<br> Input: height = [1,8,6,2,5,4,8,3,7]<br>Output: 49|
| Trapping Rain Water | https://leetcode.com/problems/trapping-rain-water/description/ | Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]<br>Output: 6|
| Swimming in rising water | https://leetcode.com/problems/swim-in-rising-water/description/ | Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).Input: grid = [[0,2],[1,3]]<br>Output: 3 Explanation:At time 0, you are in grid location (0, 0).<br>You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.<br>You cannot reach point (1, 1) until time 3.When the depth of water is 3, we can swim anywhere inside the grid.
| Largest Rectangle in Histogram | https://leetcode.com/problems/largest-rectangle-in-histogram/description/ | Input: heights [2,1,5,6,2,3] ,Output: 10<br>Explanation: The above is a histogram where width of each bar is 1.<br>The largest rectangle is shown in the red area, which has an area = 10 units.|










