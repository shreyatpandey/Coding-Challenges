class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        my_dict = {}
        final_list = []
        for i in range(0,len(paths)):
            list_split = paths[i].split()
            for j in range(1,len(list_split)):
                string_match = ''.join((re.findall(r'(?<=\().*?(?=\))',list_split[j])))
                string_split_loop = list_split[j].split('(')
                string_final_path = list_split[0] + '/' + string_split_loop[0]
                if string_match in my_dict:
                    my_dict[string_match].append(string_final_path)
                else:
                    my_dict[string_match] = [string_final_path]
                    
        for key,value in my_dict.items():
            if(len(value) > 1):
                final_list.append(value)
        
        return final_list
