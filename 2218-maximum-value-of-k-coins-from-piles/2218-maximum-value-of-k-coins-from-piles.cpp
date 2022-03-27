class Solution {
    
    int dp[1001][2001];
    
    int solve(vector<vector<int>> &piles, int pos, int k) {
        
        if(pos == piles.size() or k == 0)
            return 0;
        
        
        int &ans = dp[pos][k];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
        
        int n = piles[pos].size();
        
        int sum = 0;
        
        for(int i = 0; i <= n and i <= k; i++) {
            
            int cur = sum + solve(piles, pos + 1, k - i);
            
            if(i < n) sum += piles[pos][i];
            
            ans = max(ans, cur);
        }
        
        return ans;
        
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        memset(dp, -1, sizeof(dp));
        
        return solve(piles, 0, k);
    }
};