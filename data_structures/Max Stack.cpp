//TC: O(n)
class MaxStack {
    private :
        stack<int>HelperStack;
        stack<int>Max;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        if ( Max.size() == 0)
            Max.push(x);
        else
        {
            int MaxElement = max(x,Max.top());
            Max.push(MaxElement);
        }
        HelperStack.push(x);
        
    }
    
    int pop() {
        
        int MaxTop = Max.top();
        int Helpertop = HelperStack.top();
        Max.pop();
        HelperStack.pop();
        return Helpertop;
        
    }
    
    int top() {
        int HelperTop = HelperStack.top();
        return HelperTop;
        
    }
    
    int peekMax() {
     int MaxTop = Max.top();
     return MaxTop;
        
    }
    
    int popMax() {
        int max = Max.top();
        stack<int>Buffer;
        while(top()!= max)
        {
            Buffer.push(pop());
        }
        pop();
        while(Buffer.size()>0)
        {
            int BufferTop = Buffer.top();
            push(BufferTop);
            Buffer.pop();
            
        }
        return max;
        
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
