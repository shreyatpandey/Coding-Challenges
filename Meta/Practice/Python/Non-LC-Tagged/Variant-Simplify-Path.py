'''
Given current directory and change directory path, return final path.

For Example:


Curent                 Change            Output

/                    /facebook           /facebook
/facebook/anin       ../abc/def          /facebook/abc/def
/facebook/instagram   ../../../../.      /

'''

def change_path(current, changed):
    if not changed:
        return current
    if changed[0] == "/": #edge case
        current = ""

    path = []
    
    for segment in (current + "/" + changed).split("/"):
        if segment == "..":
            if path:
                path.pop()
        elif segment and segment != ".":
            path.append(segment)

    return "/" + "/".join(path)

if __name__ == '__main__':
    print(change_path("/", "/facebook"))
    print(change_path("/facebook/anin", "../abc/def"))
    print(change_path("/facebook/instagram", "../../../../."))

'''
Point of observation :-
If you just apply Simplify Path on a concatenation of current and change you'll miss an edge case: 
If change starts with a / current has to be emptied.
Linux will also take you to your home directory (aka ~) 
if you use cd without an argument, but I'd consider that an optional point worth discussing with your interviewer.
'''