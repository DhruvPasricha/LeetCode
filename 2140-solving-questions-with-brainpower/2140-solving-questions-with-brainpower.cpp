class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int64_t n = questions.size();
        
        vector<int64_t> dp(n + 1);
        
        for(int i = n - 1;i >= 0;i--) {
            
            // skipped
            int64_t ans1 = dp[i + 1];
            
            // solved
            int64_t points = questions[i][0];
            int64_t next = (i + 1 + questions[i][1]);
            next = min(n, next);
            int64_t ans2 = points + dp[next];
            
            // result
            dp[i] = max(ans1, ans2);
        }
        
        return dp[0];
    }
};