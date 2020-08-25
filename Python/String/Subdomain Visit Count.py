class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        my_dict = {}
        return_list = []
        for i in cpdomains:
            count,domain_name = i.split()
            count = int(count)
            domain_name_split = domain_name.split('.')
            for j in range(0,len(domain_name_split)):
                string_loop = ".".join(domain_name_split[j:])
                if string_loop not in my_dict:
                    my_dict[string_loop] = count
                else:
                    my_dict[string_loop] += count
                
        for key,values in my_dict.items():
            string_final = str(values) + " " + key
            return_list.append(string_final)
        
        return return_list
