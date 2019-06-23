lass MyQueue {
    private:
        stack<int>stack_new;
        stack<int>stack_old;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
         while (!stack_new.empty()) 
         {
            cout<<"stack_new.top():"<<stack_new.top()<<endl;
            stack_old.push(stack_new.top());
            stack_new.pop();
        }
        /*In stack_new all elements are stored as Last in First Out, and by pop and storing in stack_old it would stored in reverse order*/
        stack_new.push(x);
        /* x would be last element but when stack_new would behave as queue it would be first element in front of queue */
        while(!stack_old.empty())
        {
            stack_new.push(stack_old.top());
            stack_old.pop();        
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int val = stack_new.top();
        stack_new.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return stack_new.top();
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_new.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
