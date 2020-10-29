class Solution(object):
    def restoreIPAddresses(self,s):
        list_valid_ip_address = []
        ip_length = len(s)
        if(ip_length>12):
            return -1
        temp_string = s
        
        for i in range(1,4):
            for j in range(1,4):
                for k in range(1,4):
                    d = ip_length - (i+j+k)
                    if(d>0 and d<=3 and i+j+k+d == ip_length):
                        first_part = (temp_string[:i])
                        second_part = (temp_string[i:(i+j)])
                        third_part = (temp_string[(i+j):(i+j+k)])
                        fourth_part =(temp_string[(i+j+k):])
                        if(int(first_part)<=255 and int(second_part)<=255 and int(third_part)<=255 and int(fourth_part)<=255):
                            store_string = first_part+"."+second_part+"."+third_part+"."+fourth_part
                            if(len(store_string) == ip_length + 3):
                                list_valid_ip_address.append(store_string)
        return list_valid_ip_address

sol = Solution()
input = "25525511135"
result =sol.restoreIPAddresses(input)
if (result == -1):
    print("String_length_exceeded")
print("Possible_ip_string:",result)
