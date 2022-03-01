class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> mp;
        
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        
        stack<char> st;
        for(char ch : s) {
            
            if(mp.count(ch) == 0) {
                st.push(ch);
            } else {
                
                if(st.size() == 0 or st.top() != mp[ch])
                    return false;
                
                st.pop();
                
            }
        }
            
        return st.size() == 0;
        
    }
};