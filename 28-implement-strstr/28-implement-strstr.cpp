class Solution {
    
    vector<int> getLPS(string s) {
        
        int n = s.size();
        
        vector<int> LPS(n + 1);
        
        LPS[0] = -1;
        
        for(int i = 1;i <= n;i++) {
            int k = LPS[i - 1];
            while(k >= 0 and s[k] != s[i - 1])
                k = LPS[k];
            LPS[i] = k + 1;
        }
        
        return LPS;
    }
    
public:
    int strStr(string text, string pattern) {
           
        vector<int> LPS = getLPS(pattern + "#" + text);
        
        int patternLength = pattern.size();
        int textLength = text.size();
        
        for(int i = patternLength + 1; i < LPS.size(); i++) {
            
            if(LPS[i] == patternLength) {
                return i - 2 * patternLength - 1;
            }
        }
        
        return -1;
    }
};