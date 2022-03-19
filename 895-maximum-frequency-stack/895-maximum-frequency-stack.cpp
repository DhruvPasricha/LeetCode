class FreqStack {
    
    const int N = 2*1e4 + 10;
    
    vector<stack<int>> st;
    unordered_map<int, int> freq;
    int mx = 0;
    
public:
    FreqStack() {
        st.resize(1);
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val] == st.size()) {
            st.push_back({});
        }
        st[freq[val]].push(val);
        mx = max(freq[val], mx);
    }
    
    int pop() {
        int val = st[mx].top();
        st[mx].pop();
        freq[val]--;
        if(st[mx].size() == 0) 
            mx--;
        return val;
    }
};

