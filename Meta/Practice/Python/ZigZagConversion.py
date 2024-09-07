'''
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
'''
'''
Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
'''
'''
In this question the most important thing is getting the pattern correct. 
It is very easy to go down the wrong path and spend 10 minutes trying to figure out 
how to make a complicated algorithm work when a very easy one would suffice.

Thinking process

First I looked at the problem and thought about how the printed pattern looked like it would be mapped out on a matrix. 
I wrote out the number of "main" columns and then the number of "middle" columns

P           I         N
A      L    S     I   G
Y    A      H    R
P           I
------------------------
4     2     4     2   2(*)
The last line is 2 only because the word ends, but we can see that the pattern is 4-2-4-2-4-.... 
When drawing it out for numRows = 3, the pattern became

P         A         H         N
A    P    L    S    I    I    G
Y         I         R
---------------------------------
3    1    3    1    3    1    2(*)
Again we can see the pattern is 3-1-3-1-3-...

So the pattern of "main" rows to "mid" rows is n, n-2, n, n-2, ...

When I tried to build an algorithm for this pattern I got stuck. How would I make the index move up n, then down n-2 without confusing myself or missing edge cases?

Next I tried to write out the row of each letter in the string. For numRows = 4, it became:

P  A  Y  P  A  L  I  S  H  I  R  I  N  G
-----------------------------------------
1  2  3  4  3  2  1  2  3  4  3  2  1  2
For numRows = 3, it became:

P  A  Y  P  A  L  I  S  H  I  R  I  N  G
-----------------------------------------
1  2  3  2  1  2  3  2  1  2  3  2  1  2
This is where I found the correct pattern. 
Basically instead of worrying about "main" rows vs. "mid" rows, 
it easily maps into moving the index from 1 -> numRows, and then from numRows -> 1. 
We don't even need to think about a matrix and worrying about rows vs. columns.

Algorithm

At first I thought about how to make the different rows as strings.
How would I make row1, row2, row3? Sure if there were only a few rows I could hardcode them,
but then how would I be able to add the character to each row easily? It is too difficult, so I thought using an array would be much better.

Then I thought how would we make sure that we are going up and down in the correct pattern? 
The easiest way was to use a going_up flag to make sure to switch the direction of the index.

Lastly the only thing to check was edge cases, which by this point was pretty easy with a simple run through of the algorithm.

Code:
'''
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
            
        row_arr = [""] * numRows
        row_idx = 1
        going_up = True

        for ch in s:
            row_arr[row_idx-1] += ch
            if row_idx == numRows:
                going_up = False
            elif row_idx == 1:
                going_up = True
            
            if going_up:
                row_idx += 1
            else:
                row_idx -= 1
        
        return "".join(row_arr)
'''
Time & Space Complexity

Time: O(n)

We run through the whole string once: O(n)
everything we do inside the for loop: O(1)
Finally we join the whole array int a string: O(n)
Space: O(n)

We are creating a new array: O(n)
We are using join to put it back into a string: O(n)
'''
