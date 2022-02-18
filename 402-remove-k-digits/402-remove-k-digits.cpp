class Solution {
    
    vector<int> getNextSmallerRight(string &A) {
        
        int n = A.size();
        vector<int> Ans(n, n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0;i--) {
            
            while(st.size() and A[st.top()] >= A[i])
                st.pop();
            
            if(st.size()) 
                Ans[i] = st.top();
            
            st.push(i);
        }
        
        return Ans;
    }
    
    
public:
    string removeKdigits(string num, int k) {
        
        vector<int> nextSmallerRight = getNextSmallerRight(num);
        
        string ans = "";
        
        int n = num.size();
        
        for(int i = 0;i < n; i++) {
            
            int removeTill = nextSmallerRight[i];
           
            if(removeTill - i <= k) {
                k -= (removeTill - i);
                i = removeTill - 1;
            } else {
                
                if(ans.size() == 0 and num[i] == '0')
                    continue;
                ans += num[i];
            }
        
        } 
        
        return ans.size() == 0 ? "0" : ans;
    }
};
