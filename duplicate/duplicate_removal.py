class Solution:
    def duplicate_removal_1(self,list_input):
        new_list = []
        for i in range(0,len(list_input)):
            if list_input[i] not in new_list:
                new_list.append(list_input[i])
        return new_list
    
    def duplicate_removal_2(self,list_input):
        list_input = list(dict.fromkeys(list_input))
        return list_input

if __name__ == "__main__":
    s = Solution()
    list_input = [8,4,5,5,5,6,6,7,7,4,8]
    print("duplicate_removal_1:",s.duplicate_removal_1(list_input))
    print("duplicate_removal_2:",s.duplicate_removal_2(list_input))
    
