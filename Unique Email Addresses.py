class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
    
        list_hold = []
        for i in range(0,len(emails)):
            list_loop = emails[i].split("@")
            string_same = ""
            if '+' in str(list_loop[0]):
                list_plus_split = list_loop[0].split("+")
                if '.' in list_plus_split[0]:
                    string_same = "".join(list_plus_split[0].split("."))
                else:
                    string_same = list_plus_split[0]
            elif '.' in list_loop[0] and '+' not in list_loop[0]:
                string_same = "".join(list_loop[0].split("."))
                
            else:
                string_same = list_loop[0]
            
            string_store = string_same + "@" +list_loop[1]
            if string_store not in list_hold:
                list_hold.append(string_store)
            
        return len(list_hold)
