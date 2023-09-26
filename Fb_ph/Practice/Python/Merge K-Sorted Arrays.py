'''
TC:- O(n*k*log(k))
SC:- O(k*log(k))
'''
import heapq
def mergeKSortedArrays(lists):
    final_list = []
    heap = [(mylst[0], i, 0) for i, mylst in enumerate(lists) if mylst]
    heapq.heapify(heap)

    while heap:
        val, list_ind, element_ind = heapq.heappop(heap)
        final_list.append(val)
        if element_ind + 1 < len(lists[list_ind]):
            next_tuple = (lists[list_ind][element_ind + 1],
                          list_ind,
                          element_ind + 1)
            heapq.heappush(heap, next_tuple)
    return final_list

if __name__ == '__main__':
    Input= [[10,40,70],[20,50,80],[30,60,90]]
    print("Test Case-1:")
    print(mergeKSortedArrays(Input))
    
    Input = [[],[]]
    print("Test Case-2:")
    print(mergeKSortedArrays(Input))
    
    Input = [[1],[2,4],[3,5]]
    print("Test Case-3:")
    print(mergeKSortedArrays(Input))
    
    Input = [1],[2],[]
    print("Test Case-4:")
    print(mergeKSortedArrays(Input))
    
    
    
    
    
