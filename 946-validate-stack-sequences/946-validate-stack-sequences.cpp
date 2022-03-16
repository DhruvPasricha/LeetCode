class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        
        int i = 0;
        int j = 0;
        
        stack<int> st;
        st.push(INT_MIN);
        
        while(j < n) {
            
            while(i < n and st.top() != popped[j])
                st.push(pushed[i++]);
            
            if(st.top() != popped[j])
                return false;
            
            st.pop();
            j++;
        }
        
        return true;
        
    }
};