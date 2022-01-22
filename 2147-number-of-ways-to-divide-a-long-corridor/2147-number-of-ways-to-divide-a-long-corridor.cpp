class Solution {
    
    const int64_t mod = 1e9 + 7;
    int64_t dp[100001][3];
    
    int64_t solve(string &s, int pos, int count) {
        
        if(count > 2) return 0;
        
        if(pos == (int)s.size()) {
            return count == 2;
        }
        
        if(dp[pos][count] != -1) return dp[pos][count];
        
        int64_t ans = 0;
        
        // don't partition
        int64_t ans1 = solve(s, pos + 1, count + (s[pos] == 'S'));
        
        // partition
        if(count == 2 and pos + 1 != s.size()) {
            int64_t ans2 = solve(s, pos, 0);
            ans = ans2;    
        }
        
        ans = (ans + ans1) % mod;
        return dp[pos][count] = ans;
    }
    
public:
    int numberOfWays(string s) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(s, 0, 0);
        
        return ans;
    }
};