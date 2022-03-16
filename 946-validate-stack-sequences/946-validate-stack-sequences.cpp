class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        
        int i = 0;
        int j = 0;
        
        
        stack<int> st;
        
        while(i < n or j < n) {
            
            if(i < n and (st.empty() or st.top() != popped[j]))
                st.push(pushed[i++]);
            else if(st.top() == popped[j])
                j++, st.pop();
            else
                return false;
        }
        
        return true;
        
    }
};