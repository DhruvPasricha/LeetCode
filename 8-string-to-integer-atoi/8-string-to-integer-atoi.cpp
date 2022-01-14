class Solution {
    
    void ignoreWhiteSpaces(const string &s, int &i, const int &n) {
        while(i < n and s[i] == ' ') {
            i++;
        }
    }
    
    bool isDigit(const char &d) {
        return d >= '0' and d <= '9';
    }
    
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        int64_t ans = 0;
        const int64_t inf = (int64_t)INT_MAX + 1;
        
        ignoreWhiteSpaces(s, i, n);
        
        bool isNegative = (i < n and s[i] == '-');
        
        if(isNegative or (i < n and s[i] == '+')) 
            i++;
    
        while(i <  n and isDigit(s[i])) { 
            if(ans >= inf) break;
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        
        if(ans >= inf) {
            if(isNegative) return INT_MIN;
            return INT_MAX;
        }
        
        if(isNegative) ans = -ans;
        
        return ans;
    }
};