def SimplifyPath(path):
    result = "/"
    stk = []
    listpath = path.split("/")
    for char in listpath:
        if char == ".." :
            if len(stk) > 0:
                del stk[-1]
        elif char == "." or char =='':
            continue
        
        else:
            stk.append(char)
    
    while len(stk) > 0:
        lastchar = stk[0]
        del stk[0]
        if len(stk) == 0:
            result += lastchar
        else:
            result += lastchar + "/"
    
    return result
  
path = "/../"
result = SimplifyPath(path)
print("result:",result)

path = "/a/./b/../../c/"
result = SimplifyPath(path)
print("result-1:",result)

path = "/home//food"
result = SimplifyPath(path)
print("Result-2:",result)
