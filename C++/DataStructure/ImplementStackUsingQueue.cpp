class MyStack {
    private:
        queue<int>queue_new; /* this will act as a stack*/
        queue<int>queue_old;
        int top_element = 0;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        queue_new.push(x);
        while (queue_new.size() > 1 ) 
        {
            queue_old.push(queue_new.front()); /*why queue_new.front() ?it is used to maintain last in first out*/
            queue_new.pop();
        }
    
    }
    
    /** Removes the element on top of the stack and returns that element */
    int pop() 
    {
        int x = top(); 
        queue_new.pop();
        return x;
      
    }
    
    /** Get the top element. */
    int top() {
       if (queue_new.empty()) 
       {
             for ( int i = 0 ; i < ( int )queue_old.size() - 1 ; ++ i) 
             {
                queue_old.push(queue_old.front()); 
                queue_old.pop();
            }
            
            queue_new.push(queue_old.front()); 
            queue_old.pop();
        }
        return queue_new.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() 
    {
        return queue_new.empty() && queue_old.empty();
        
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
