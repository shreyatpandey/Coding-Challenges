'''
It handles duplicates as well
'''
def mergeThreeSortedArrays(A,B,C):
    index1 = index2 = index3 = 0
    previous = float("-inf")
    results = []
    while (index1 < len(A) or index2 < len(B) or index3 < len(C)):
        a = A[index1] if index1<len(A) else float("inf")
        b = B[index2] if index2<len(B) else  float("inf")
        c = C[index3] if index3<len(C) else float("inf")
        minVal = min(a,min(b,c))
        if (minVal > previous): 
            results.append(minVal)
            previous = minVal
            
        if (index1 < len(A) and A[index1] == minVal): 
            index1 += 1
         
        if (index2 < len(B) and B[index2] == minVal):
            index2 += 1
         
        if (index3 < len(C) and C[index3] == minVal):
              index3 += 1
    return results
if __name__ == '__main__':
    print("Test Case:-1")
    A = [1, 2, 3, 4, 5]
    B = [1,1,1]
    C = [2,2,6]
    print(mergeThreeSortedArrays(A,B,C))
    print('\n')
    print("Test Case:-2")
    A = [4,4,4]
    B = [3,3,3]
    C = [2,2,2]
    print(mergeThreeSortedArrays(A,B,C))

'''
Test Case:-1
[1, 2, 3, 4, 5, 6]


Test Case:-2
[2, 3, 4]


'''
