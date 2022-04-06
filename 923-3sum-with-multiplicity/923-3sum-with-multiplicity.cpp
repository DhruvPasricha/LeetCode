class Solution {
    
    const int64_t mod = 1e9 + 7;
    int64_t dp[3001][301][4];
    
    int64_t solve(vector<int> &A, int n, int target, int req) {
        
        if(target < 0)
            return 0;
        
        if(n == 0)
            return target == 0 and req == 0;
        
        auto &ans = dp[n][target][req];
        
        if(ans != -1)
            return ans;
        
        int64_t ans1 = solve(A, n - 1, target, req);
        int64_t ans2 = (req) ? solve(A, n - 1, target - A[n-1], req - 1) : 0;
        
        return ans = (ans1 + ans2) % mod;
    }
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(arr, arr.size(), target, 3);
        return ans;
    }
};