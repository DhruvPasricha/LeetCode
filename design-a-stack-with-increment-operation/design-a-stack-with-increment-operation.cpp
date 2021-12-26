class CustomStack {
    vector<int> st;
    vector<int> diffArray;
    int top;
public:
    CustomStack(int maxSize) {
        top = -1;
        st.resize(maxSize);
        diffArray.resize(maxSize);
    }
    
    void push(int x) {
        if(top + 1 >= st.size()) return;
        st[++top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int ans = st[top] + diffArray[top];
        top--; // popped it
        if(top != -1) diffArray[top] += diffArray[top + 1];
        diffArray[top + 1] = 0;
        return ans;
    }
    
    void increment(int k, int val) {
        
        int lastIdx = min(k - 1, top);
        if(lastIdx >= 0) diffArray[lastIdx] += val;
    }

};