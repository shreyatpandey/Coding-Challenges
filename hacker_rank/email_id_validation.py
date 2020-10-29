'''
You must print each valid email address in the same order as it was received as input.

Sample Input

2  
DEXTER <dexter@hotmail.com>
VIRUS <virus!@variable.:p>
Sample Output

DEXTER <dexter@hotmail.com>
'''

import re
number_of_email_address = int(input())
for i in range(0,number_of_email_address):
    email_id = input()
    email_id_split = email_id.split(' ')
    print("email_id_split:",email_id_split)
    email_match = re.match(r'<[A-Za-z](\w|-|\.|_)+@[A-Za-z]+\.[A-Za-z]{1,3}>',email_id_split[1])
    if email_match:
        print(email_id_split[0],email_id_split[1])
        
