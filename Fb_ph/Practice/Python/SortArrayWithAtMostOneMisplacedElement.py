'''
A sorted array with at most one misplaced element
'''
'''
Check if the index is given or not
'''
'''
Complexity:-
Tc:- O(n)
Sc:- O(1)
'''
def misplacedElement(arr):
    
    # Traversing element of array.
    n = len(arr)
    pos = -1
    for i in range(1,len(arr)):
        if arr[i] < arr[i-1]:
            pos = i
    if pos == -1:
        return 
    
    for i in range(n):
        # For the element on left of pos
        if (i < pos):
            if (arr[pos] < arr[i]):
                temp = arr[pos]
                arr[pos] = arr[i]
                arr[i] = temp
 
        # For the element on right of pos
        elif (i > pos):
            if (arr[pos] > arr[i]):
                temp = arr[pos]
                arr[pos] = arr[i]
                arr[i] = temp
                pos = i
    print("listInput:",arr)

if __name__ == '__main__':
    print("Test Case:-1")
    misplacedElement([1,3,5])
    
    print("Test Case:-2")
    misplacedElement([2,6,3,4,7,9])
    
    print("Test Case:-3")
    misplacedElement([2,3,6,7,9,4])
    
    print("Test Case-4:")
    misplacedElement([4,5,6,7,1])
    
    print("Test Case-5:")
    misplacedElement([4,5,6,7,8,9,11,12,13,14,3])

    print("Test Case-6:")
    misplacedElement([2,4,6,1,7,9])
    
    
