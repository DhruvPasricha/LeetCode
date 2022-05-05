class MyStack {
    
    queue<int> q;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);        
    }
    
    int pop() {
        
        int ans = top(true);
        return ans;
    }
    
    int top(bool toBePopped = false) {
        
        int n = q.size();
        for(int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        
        int ans = q.front();
        
        if(not toBePopped)
            q.push(q.front());
        
        q.pop();
        
        return ans;
    }
    
    bool empty() {
        return q.size() == 0;
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