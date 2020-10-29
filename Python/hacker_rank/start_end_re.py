'''
Print the tuple in this format: (start _index, end _index). 
If no match is found, print (-1, -1).

Sample Input

aaadaa
aa
Sample Output

(0, 1)  
(1, 2)
(4, 5)
'''
import re
string_main = input()
string_compare = input()
index_string_compare = 0

if re.search(string_compare,string_main):
    while index_string_compare + len(string_compare) < len(string_main) :
        string_result= re.search(string_compare,string_main[index_string_compare:])
        print("({0},{1})\n".format(index_string_compare+string_result.start(),index_string_compare+string_result.end()-1))
        index_string_compare += string_result.start() + 1
else:
    print("1,-1")
