'''
Given N sorted Array find k smallest elements
'''
'''
TC:- O(NlogN)
SC:- O(N) for heap
'''
import heapq
def findKsmallestElements(arrs,k):
    pq = []
    for i,arr in enumerate(arrs):
        heapq.heappush(pq,(arr[0],i,1))
    print(pq)
    answer = []
    while len(pq) >0 and len(answer)<k:
        v,i,j = heapq.heappop(pq)
        answer.append(v)
        if j == len(arrs[i]):
            continue
        heapq.heappush(pq,(arrs[i][j],i,j+1))
        print(pq)
    return answer

if __name__ == '__main__':
    inputArray =[[25, 27,  29, 100],
                [ 3,  83, 400, 500],
                [ 2,  5,  12,  13]]
    print(findKsmallestElements(inputArray,6))
#Output Trace
'''
[(2, 2, 1), (25, 0, 1), (3, 1, 1)]
[(3, 1, 1), (25, 0, 1), (5, 2, 2)]
[(5, 2, 2), (25, 0, 1), (83, 1, 2)]
[(12, 2, 3), (83, 1, 2), (25, 0, 1)]
[(13, 2, 4), (83, 1, 2), (25, 0, 1)]
[(27, 0, 2), (83, 1, 2)]
[2, 3, 5, 12, 13, 25]
'''
