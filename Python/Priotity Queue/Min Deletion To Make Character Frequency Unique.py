import heapq as heap
def MinNoOfOperation(string):
    hashMap = {}
    for char in string:
        hashMap[char] = hashMap.get(char,0) + 1
    #Brain Fart could not think of ways to get only values from hashMap
    maxheap = []
    minNoOfChar = 0
    for key,values in hashMap.items():
        heap.heappush(maxheap,-values) #heappush <-> O(nlog(n))

    #maxheap = list(hashMap.values())
    '''
    improvise to O(n) using heapify
    heapify will not work
    '''
    #heap.heapify(maxheap)

    
    while len(maxheap)-1 > 0: #O(N)
        currentFreq = heap.heappop(maxheap) #O(log(N))
        '''
        Reason property of heap cannot be maintained with step of maxheap[0] followed by del maxheap[0]
        use-->heappop
        '''
        if currentFreq == maxheap[0] : #if the freq are same
            if currentFreq + 1 < 0:
                heap.heappush(maxheap,currentFreq+1)
            minNoOfChar += 1
    return minNoOfChar
