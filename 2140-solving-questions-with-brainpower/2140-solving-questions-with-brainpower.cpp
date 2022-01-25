
class Solution {
    #define v vector
    v<int64_t> dp;
    
    int64_t solve(v<v<int>> &A, int pos) {
        
        if(pos >= A.size()) 
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int64_t ans1 = solve(A, pos + 1);
        int64_t ans2 = (int64_t)(A[pos][0]) + solve(A, pos + 1 + A[pos][1]);
        
        return dp[pos] = max(ans1, ans2);
        
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        dp.assign(questions.size(), -1);
        
        int64_t ans = solve(questions, 0);
        
        return ans;
    }
};