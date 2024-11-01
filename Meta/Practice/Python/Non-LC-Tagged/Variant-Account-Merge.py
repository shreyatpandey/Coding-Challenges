'''
Input:
# C1: bob@yahoo.com, bob@gmail.com
# C2: mary@facebook.com
# C3: bob@gmail.com, bob_1@hotmail.com
# C4: bob_1@hotmail.com
# C5: mary@facebook.com
# C6: mark@gmail.com
-----
# C1: e1, e2,
# C2: e2, e3,
# C3: e3, e4,
# ....
# CN: eN, eN+1

# Output:
#     ((C1, C3, C4), (C2, C5), (C6))
'''

from collections import defaultdict
def accountsMerge(account) :
    graph = defaultdict(set)
    for name in account:
        for email in account[name]:
            graph[name].add(email)
            graph[email].add(name)

    # Step 2: Search for connected components
    components, seen, i = defaultdict(list), set(), 0

    def dfs(node, i):
        if node in  account:  # This is to filter the customer name from email
            components[i].append(node)
        seen.add(node)
        for neighbour in graph[node]:
            if neighbour not in seen:
                    dfs(neighbour, i)

    # Step 3: Group Connected component
    for email in graph:
        if email not in seen:
                dfs(email, i)
        i += 1
    
    # print values
    print(components.values())

if __name__ == '__main__':
    Accounts = {
                 'C1': ['bob@yahoo.com', 'bob@gmail.com'],
                 'C2': ['mary@facebook.com'],
                 'C3': ['bob@gmail.com', 'bob_1@hotmail.com'],
                 'C4': ['bob_1@hotmail.com'],
                 'C5': ['mary@facebook.com'],
                 'C6': ['mark@gmail.com', 'antony@gmail.com']
               }

    result = accountsMerge(Accounts)
