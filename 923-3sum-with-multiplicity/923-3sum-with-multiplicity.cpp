class Solution {
    
    const int64_t mod = 1e9 + 7;
    int64_t dp[1002][301][4];
    
    
    int64_t nCr(int n, int r) {
        
        int64_t num = 1;
        int64_t den = 1;
        
        for(int64_t i = 0; i < r; i++) {
            num *= (n - i);
            den *= (i + 1);
        }
        
        return num / den;
        
    }
    
    int64_t solve(vector<int> &A, int n, int target, int req) {
        
        if(target < 0)
            return 0;
        
        if(n == 0)
            return target == 0 and req == 0;
        
        auto &ans = dp[n][target][req];
        
        if(ans != -1)
            return ans;
            
        int mx = min(A[n - 1], req);
        int curSum = 0;
        ans = 0;
        
        for(int i = 0;i <= mx; i++) {
            auto cur = solve(A, n - 1, target - curSum, req - i);     
            cur *= nCr(A[n - 1], i);  
            cur %= mod;
            ans += cur;
            ans %= mod;
            curSum += n - 1;
        }
        
        return ans;
        
    }
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        vector<int> freq(101);
        
        for(int &x : arr)
            freq[x]++;
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(freq, 101, target, 3);
        
        return ans;
    }
};