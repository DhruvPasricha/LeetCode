class Solution {
    
    bool isDigit(char ch) {
        return ch >= '0' and ch <= '9';
    }
public:
    int calculate(string s) {
        
        int n = s.size();
        
        int i = 0;
        
        stack<string> st; 
        while(i < n) {
            if(s[i] == ' '){
                i++;
                continue;
            }
            int j = i;
            string cur = "";
            while(j < n and isDigit(s[j])) {
                cur += s[j];
                j++;
            }
            while(j < n and s[j] == ' ') j++;
            
            if(st.size() == 0 or st.top() == "+" or st.top() == "-") {
                st.push(cur);    
            } else {
                string op = st.top();
                st.pop();
                int a = stoi(st.top());
                st.pop();
                int b = stoi(cur);
                if(op == "*") st.push(to_string(a*b));
                else st.push(to_string(a/b)); 
            }
            if(j < n) st.push(s.substr(j, 1));
            i = j + 1;
        }
        
        int ans = 0;
        
        while(st.size() > 0) {
            
            int cur = stoi(st.top());
            st.pop();
            if(st.size() > 0) {
                if(st.top() == "+") ans += cur;
                else ans -= cur;
                st.pop();
            } else {
                ans += cur;
            }
        }
        return ans;
    }
};


