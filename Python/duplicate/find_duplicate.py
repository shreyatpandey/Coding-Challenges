class Solution:
    def duplicates(self,list_input):
        for i in list_input:
            if list_input.count(i)>1:
                return list_input[i]

if __name__ == "__main__":
    s = Solution()
    list_input = [3,2,4,3]
    result = s.duplicates(list_input)
    print("result:",result)
