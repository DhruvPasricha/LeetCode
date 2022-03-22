class Solution {
    
    int dp[32][2][2];
    
    string to_binary(int n) {
        
        string ans = "";
        
        while(n) {
            
            if(n & 1) ans += '1';
            else ans += '0';
            
            n >>= 1;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    int solve(string &s, int pos, bool tight, int prev) {
        
        
        if(pos == s.size())
            return 1;
        
        int &ans = dp[pos][tight][prev];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
    
        ans += solve(s, pos + 1, tight and s[pos] == '0', 0);
        
        if(prev != 1 and (not tight or s[pos] == '1'))
            ans += solve(s, pos + 1, tight, 1);
        
        return ans;
    }
    
public:
    int findIntegers(int n) {
        
        memset(dp, -1, sizeof(dp));
        
        auto s = to_binary(n);
        
        int ans = solve(s, 0, true, 0);
        return ans;
        
    }
};