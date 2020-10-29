def generate_binary_string(k):
    list_binary = []
    if (k<0):
        print("Negative")
    else:
        for i in range(0,pow(2,k)):
            s = bin(i)[2:]
            s = "0"*(k-len(s)) + s
            list_binary.append(s) 
    return list_binary
            
#generate all permuation of string with given k
def permutation_string(str,k):
    permutation_string_input = []
    for i in range(0,len(str)):
        if k== 1:
            permutation_string_input.append(str[i])
        else:
            for j in permutation_string(str[i+1:],k-1):
                permutation_string_input.append(str[i]+j)
    
    return permutation_string_input

def check_permutation_string(input_str,k):
    result_string_list = permutation_string(input_str,k)
    result_binary_list = generate_binary_string(k)
    for k in range(0,len(result_binary_list)):
        flag = 0
        for j in range(0,len(result_string_list)):
            if(result_binary_list[k] == result_string_list[j]):
                flag+=1
        if (flag == 0):
            print("Does not contain all the permuation")
            break
    
    if(flag!=0):
        print("Contain all the permutation")
    

final_result = check_permutation_string("11001",2)
    
