'''
Complexity
n = length of words
k = avg length of a word
m = maxWidth
Python has immutable string, while in C++ it's mutable
Tc:-
O(n.k)
Main while loop is O(n)
For for loop to create a line
O(m) on avg we can fit m/k words per line
Because we have n words, that implies O(n/m/k) = O(n.k/m) iterations
Each iteration costs O(m) so total is O(n.k)

Sc:- 
O(m) as we don't count the answer as part of the space complexity
We need to check one line at a time and each line has a length of m.
'''
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        Result = []
        line,length = [],0
        i = 0

        while i< len(words):
            if length + len(line) + len(words[i]) > maxWidth:
                # Line complete by using extra spaces 
                # Need to distribute spaces evenly between words
                # if the number of spaces is not even, left space should have more
                #space than right
                extra_space = maxWidth - length
                spaces = extra_space// max(1,len(line)-1)
                remainder = extra_space % max(1,len(line)-1)

                for j in range(max(1,len(line)-1)): #create line spaces
                    line[j] += " "*spaces
                    if remainder:
                        line[j] += " "
                        remainder -= 1
                Result.append("".join(line))
                line,length = [],0 # Reset line and length
            
            line.append(words[i])
            length += len(words[i])
            i += 1
        
        #Handling the last line
        last_line = " ".join(line) #"" vs " " there is a difference in python
        trail_space = maxWidth - len(last_line)
        Result.append(last_line + " "*trail_space)
        return Result
