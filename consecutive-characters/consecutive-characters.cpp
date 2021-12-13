class Solution {
public:
    int maxPower(string s) {
        
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            
            int j = i;
            int cur = 0;
            while(j < n and s[i] == s[j]) j++, cur++;
            ans = max(ans, cur);
            i = j - 1;
        }
        return ans;
    }
};