'''
Sample Input 0

4
4.0O0
-1.00
+4.54
SomeRandomStuff

Sample Output 0

False
True
True
False

'''
import re
number_of_line = int(input())
for i in range(0,number_of_line):
    each_line = input()
    regular_expression = r'^[-+]?[0-9]*\.[0-9]+$'
    if re.match(regular_expression,each_line):
        print("True")
    else:
        print("False")
