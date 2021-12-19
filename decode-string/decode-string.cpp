class Solution {
    map<int, int> correspondingClosingBracket;
public:
    
    bool isLowerCase(char ch) {
        return ch >= 'a' and ch <= 'z';
    }
    
    bool isDigit(char ch) {
        return ch >= '0' and ch <= '9';
    }
    
    string solve(string &s, int start, int end) {
        
        if(start > end) return "";
        if(start == end) return s.substr(start,1);
        
        string ans = "";
        
        if(isLowerCase(s[start])) {
            while(start <= end and isLowerCase(s[start])) {
                ans += s[start];
                start++;
            }
            ans += solve(s, start, end);
        } else {
            
            int current = 0;
            while(start <= end and isDigit(s[start])) {
                current = current * 10 + (s[start] - '0');
                start++;
            }
            string temp = solve(s, start + 1, correspondingClosingBracket[start] - 1);
            while(current > 0) {
                ans += temp;
                current--;
            }
            ans += solve(s, correspondingClosingBracket[start] + 1, end);
        }
        return ans;
    }
    
    string decodeString(string &s) {
        
        int n = s.size();
        stack<int> st;
        for(int i = 0;i < n;i++) {
            if(s[i] != '[' and s[i] != ']') continue;
            
            if(s[i] == '[') st.push(i);
            else {
                correspondingClosingBracket[st.top()] = i;
                st.pop();
            }
        }
        string ans = "";
        ans = solve(s, 0, n - 1);
        return ans;
    }
};