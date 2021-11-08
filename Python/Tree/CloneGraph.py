'''
Clone a Graph:-
Time-Complexity:- O(V+E)
Algo:-
Data-Structure:- 
(1) Hash-Map
name it as Map = {}
Need a dfs recursive call
    def clone(node):
        check if new node is present in Map
            if true return the new node :- Map[node]
        if not make copy of that node
            copy = Node(node.val)
            update the Map :-
            Map[node] = copy
            for neighbor in node.neighbors:
                copy.neighbors.append(clone(neighbor))
            return clone
    return clone(node) if node else return None
'''
