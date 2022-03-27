class Solution {
    
    int dp[1001][2001];
    
    int solve(vector<vector<int>> &piles, int n, int k) {
        
        if(n == 0 or k == 0)
            return 0;
        
        int &ans = dp[n][k];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
        
        int m = piles[n - 1].size();
        
        int sum = 0;
        
        for(int i = 0; i <= m and i <= k; i++) {
            
            int cur = sum + solve(piles, n - 1, k - i);
            
            if(i < m) sum += piles[n - 1][i];
            
            ans = max(ans, cur);
        }
        
        return ans;
        
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        memset(dp, -1, sizeof(dp));
        
        return solve(piles, piles.size(), k);
    }
};