class MyStack {
    
    queue<int> q;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        q.push(x);
    }
    
    int pop() {
        int ans = q.back();
        int n = q.size();
        for(int i = 0;i < n - 1;i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return ans;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.size() == 0;   
    }
};
