class Solution:
    def accountsMerge(self, accounts):
        
        em_to_name = defaultdict(list)
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
                em_to_name[email].append(name)
                
        # print(em_graph)
        # print(em_to_name)
    
        seen = set()
        checkComponents = defaultdict(list)
        index = 0
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
                print("components:",component)
                finalValue =[]
                for comp in component:
                    values = em_to_name[comp]
                    for val in values:
                        if val not in finalValue:
                            finalValue.append(val)
                checkComponents[index].append(finalValue)
                index += 1
                # after geting all connect comonent
                # we sorted the as question
                # and search the owner of the starting email
                # append in the ans
        ans.append(checkComponents.values())
        return ans
if __name__ == '__main__':
    s = Solution()
    Accounts=  [ ["C1","bob@yahoo.com", "bob@gmail.com"],["C2","mary@facebook.com"],["C3","bob@gmail.com", "bob_1@hotmail.com"] ,["C4","bob_1@hotmail.com"],
            ["C5","mary@facebook.com"] ,  ["C6","mark@gmail.com"]]

    result = s.accountsMerge(Accounts)
    print("Result:",result)
