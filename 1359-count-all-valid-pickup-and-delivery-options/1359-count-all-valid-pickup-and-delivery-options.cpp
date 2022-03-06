class Solution {
    
    const int64_t mod = 1e9 + 7;
    int64_t dp[501][501];
    
    
    int64_t solve(int pickedUp, int delivered, int n) {
        
        if(pickedUp == n and delivered == n) return 1;
        
        int64_t &ans = dp[pickedUp][delivered];
        
        if(ans != -1) return ans;
        
        ans = 0;
        
        // pickup any remaining good
        if(pickedUp < n) {
            ans = (ans + (n - pickedUp) * solve(pickedUp + 1, delivered, n)) % mod;
        }
        
        
        // deliver any picked up good
        if(pickedUp > delivered) {
            ans = (ans + (pickedUp - delivered) * solve(pickedUp, delivered + 1, n)) % mod;
        }
        
        
        return ans;
        
    }
    
    
public:
    int countOrders(int n) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(0, 0, n);
        return ans;
    }
};
 
 