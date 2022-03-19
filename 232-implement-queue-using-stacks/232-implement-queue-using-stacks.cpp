class MyQueue {
    
    stack<int> s1;
    stack<int> s2;
    
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);   
    }
    
    int pop() {
        
        int ans = peek();
        
        s2.pop();
        
        return ans;
           
    }
    
    int peek() {
        
        if(s2.size() == 0) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() and s2.empty();
    }
};
