#include<bits/stdc++.h>
using namespace std;

/*
Analysis:-
if front index and last index match, then circular queue could would be considered as full
Advantage of Circular Queue over Standard Queue, is that the space in front of the queue can be used even.
In standard queue , once the queue becomes full, inserting element is not possible even if the queue has space in fron of it.
Reason of using modulo operator :- % 
(1) To reuse the cleared space at the beginning of the queue without the need to constantly reallocate with push and shift operations
To get the rear element , use
(RearIndex + CircularQueue.size()-1) % CircularQueue.size()
replacing (frontIndex + CircularQueue.size()-1 ) % CircularQueue.size() would also work
*/


class MyCircularQueue {
    private :
        vector<int>CircularQueue ;
        int MonitorQueueSize  ;
        int FrontIndex ; 
        int LastIndex  ;
public:
    MyCircularQueue(int k):CircularQueue(k),MonitorQueueSize(0),FrontIndex(0),LastIndex(0) {
      
    }
    
    bool enQueue(int value) {
        if ( isFull() )
            return false;
        CircularQueue[LastIndex] = value;
        LastIndex = (LastIndex+1)%CircularQueue.size();
        MonitorQueueSize +=1 ;
        return true;
    }
    
    bool deQueue() {
        if ( isEmpty() )
            return false;
        
        FrontIndex = (FrontIndex + 1) %CircularQueue.size();
        MonitorQueueSize -= 1 ;
        return true;
    }
    
    int Front() {
        return !(isEmpty()) ? CircularQueue[FrontIndex] : -1 ;
    }
    
    int Rear() {
        return !(isEmpty()) ? CircularQueue[(LastIndex+CircularQueue.size()-1)%CircularQueue.size()] : -1 ;   
        
    }
    
    bool isEmpty() {
        if ( MonitorQueueSize == 0 || CircularQueue.empty() ) 
        {
            return true;
        }
        else
            return false; 
    }
    
    bool isFull() {
        return MonitorQueueSize == CircularQueue.size() ? true:false ;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
