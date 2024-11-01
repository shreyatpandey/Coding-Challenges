'''
Input:- 
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. 
The accounts themselves can be returned in any order.

'''


'''
Approach-1: DFS Iterative
'''
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        
        em_to_name = {}
        em_graph = defaultdict(set)
        
        for acc in accounts:
            name = acc[0]
            
            # making a graph of common connected gmail
            # all acc the gamil start with 1 index
            for email in acc[1:]:
                
                # connect 1st to 2nd email
                em_graph[acc[1]].add(email)
                
                #connect 2nd to 1st email
                em_graph[email].add(acc[1])
                
                # create a hashmap
                # it help us to find the email owners
                em_to_name[email] = name
                
        # print(em_graph)
        # print(em_to_name)
    
        seen = set()
        ans = []
        
        # here we use loop to traverse all unconnected
        # components of the graph
        for email in em_graph:
            if email not in seen:
                seen.add(email)
                st = [email]
                component = []
                
                # this loop give us the all conneted path as here
                # all common gmail as a list in comonent
                while st:
                    edge = st.pop()
                    component.append(edge)
                    for nei in em_graph[edge]:
                        if nei not in seen:
                            seen.add(nei)
                            st.append(nei)
                            
                # after geting all connect comonent
                # we sorted the as question
                # and search the owner of the starting email
                # append in the ans
                ans.append([em_to_name[email]] + sorted(component))
        return ans
      
'''
  Approach-2: DFS Recursive
  Time-Complexity:- O(NKLog(NK)
  where N is the number of accounts and K is the maximum length of the account
  Space-Complexity:- O(NK)
  Adjacency List:- O(NK)
  Visited Set:- O(NK)
  Stack:- O(NK)
'''
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:        
        
        em_to_name = {}
        em_graph = defaultdict(set)
        
        for acc in accounts:
            name = acc[0]
            
            # making a graph of common connected gmail
            # all acc the gamil start with 1 index
            for email in acc[1:]:
                
                # connect 1st to 2nd email
                em_graph[acc[1]].add(email)
                
                #connect 2nd to 1st email
                em_graph[email].add(acc[1])
                
                # create a hashmap
                # it help us to find the email owners
                em_to_name[email] = name
                
        # print(em_graph)
        # print(em_to_name)

        seen = set()
        ans = []
        
        # dfs function
        def dfs(s,comp):
            if s in seen:
                return
            seen.add(s)
            comp.append(s)
            for nei in em_graph[s]:
                if nei not in seen:
                    dfs(nei,comp)    
            return comp  
        
        # here we use loop to traverse all unconnected
        # components of the graph
        for email in em_graph:
            if email not in seen:
                component = []
                dfs(email, component)
                ans.append([em_to_name[email]] + sorted(component))
                
        return ans
'''
Approach-3: BFS Traversal
Time-Complexity:- O(NKLog(NK)
where N is the number of accounts and K is the maximum length of the account
Space-Complexity:- O(NK)
Adjacency List:- O(NK)
Visited Set:- O(NK)
Stack:- O(NK)
'''
from collections import defaultdict
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        
        emGraph = defaultdict(set)
        emName = {}
        for email in accounts:
            name = email[0]
            for emails in email[1:]:
                emGraph[email[1]].add(emails)
                emGraph[emails].add(email[1])
                        
                emName[emails] = name
        #print("emGraph",emGraph)
        #print("emName:",emName)
        
        '''
        Traverse the connected components
        '''
        ans = []
        visited = set()
        
        for email in emGraph:
            if email not in visited:
                visited.add(email)
                q = []
                q.append(email)
                components = []
                
                while q:
                    edge = q.pop()
                    components.append(edge)
                    for neighbours in emGraph[edge]:
                        if neighbours not in visited:
                            q.append(neighbours)
                            visited.add(neighbours)
                
                components.sort()
                components.insert(0,emName[email])
                ans.append(components)
                #ans.append(components.insert(emName[email],0))
        
        return ans
  
