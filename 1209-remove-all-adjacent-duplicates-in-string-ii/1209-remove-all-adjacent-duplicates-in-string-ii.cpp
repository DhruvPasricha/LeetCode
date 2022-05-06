class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> st;
        
        int i = 0;
        int n = s.size();
        
        while(i < n) {
            
            int count = 0;
            
            int j = i;
            
            while(j < n and s[i] == s[j])
                j++, count++;
            
            
            if(st.size() and st.top().first == s[i]) {
                count += st.top().second;
                st.pop();
            }
            
            
            count %= k;
            
            
            if(count)
                st.push({s[i], count});
            
            i = j;
        }
        
        string ans = "";
        while(st.size()) {
            
            while(st.top().second--) {
                ans += st.top().first;
            }
            
            st.pop();
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};