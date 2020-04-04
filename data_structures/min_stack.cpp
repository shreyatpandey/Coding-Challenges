//Approach-1: 99 % faster
class MinStack {    
    vector<int>input_stack;
    vector<int>min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        input_stack.push_back(x);
        if(min_stack.empty())
        {
            min_stack.push_back(x);
        }
        else
        {
            long min_value = min(min_stack.back(),x);
            min_stack.push_back(min_value);
        }
        
    }
    
    void pop() {
        input_stack.pop_back();
        min_stack.pop_back();
        
    }
    
    int top() {
        return input_stack.back();
        
    }
    
    int getMin() {
        return min_stack.back();
        
    }
};
// Approach 2: Using Stack , 22.19% faster
class MinStack {
    stack<int>MinValStack ;
    stack<int>InputStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        InputStack.push(x) ;
        if ( MinValStack.size() == 0)
        {
            MinValStack.push(x);
        }
        else
        {
            int MinValue = min(MinValStack.top(),x);
            MinValStack.push(MinValue) ;
        }
        
    }
    
    void pop() {
        MinValStack.pop();
        InputStack.pop();
    }
    
    int top() 
    {
        return InputStack.top() ;
        
    }
    
    int getMin() {
        return MinValStack.top() ;
        
        
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
