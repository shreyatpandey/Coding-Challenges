'''
Sample Input 0

100,000,000.000
Sample Output 0

100
000
000
000
'''
import re
string_input = input().strip(",.")
regex_output = re.split('[.,]+',string_input)
print("output:",*regex_output,sep='\n') # '*" takes a list and unpacks into separate argument
