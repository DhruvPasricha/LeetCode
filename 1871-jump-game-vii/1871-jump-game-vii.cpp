class Solution {
    int solve(string &s, int mn, int mx) {
        int n = s.size();
        
        vector<int> dp(n + 1, 0);
        
        dp[n - 1] = (s[n - 1] == '0');
        
        for(int i = n - 2;i >= 0;i--) {
            
            if(s[i] == '0'){
                int start = i + mn;
                int end = min(n - 1, i + mx);
                if(start <= n - 1) 
                    dp[i] = (dp[start] - dp[end + 1] > 0);
            }
            
            dp[i] += dp[i + 1];
        }
        
        return dp[0] - dp[1];
    }
    
public:
    bool canReach(string s, int minJump, int maxJump) {
        return solve(s, minJump, maxJump);
    }
};