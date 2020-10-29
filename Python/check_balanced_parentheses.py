expression = "()[][{{()}}"
count = []
closing_bracket = ['}',')',']']
flag = 1
    
for i in range(0,len(expression)):
    if(expression[i] == '{' or expression[i] == '(' or expression[i] == '['):
        count.append(expression[i])
        print("Count:",count)
    if not count:
        #return (-1)
        print ("Count is empty:")
    
    if(expression[i] == closing_bracket[0]):
        character_store = count[-1] # last element in count
        count.pop()
        print("Character_store:",character_store)
        if(character_store == '(' or character_store == '[' ):
            flag = 0
    
    if(expression[i] == closing_bracket[1]):
        character_store = count[-1]
        count.pop()
        print("Character_store:",character_store)
        if(character_store == '{' or character_store == '['):
            flag = 0
            
    
    if(expression[i] == closing_bracket[2]):
        character_store = count[-1]
        count.pop()
        print("Character_store:",character_store)
        if(character_store == '(' or character_store == '{'):
            flag = 0
            

print("Count:",count)
print("Length_count:",len(count))
if(len(count)!=0 or flag!=1):
    print("Not balanced list")
else:
    print("Balanced list")
