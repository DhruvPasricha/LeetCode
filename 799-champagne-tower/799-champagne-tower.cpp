class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        int n = query_row + 1;
        
        vector<vector<long double>> dp(n + 1);
        
        for(int i = 0; i < n; i++) 
            dp[i].resize(i + 1);
        
        dp[0][0] = poured;
        
        
        for(int i = 1; i < n; i++) {
            
            int m = i + 1;
            
            for(int j = 0; j < m; j++) {
                
                if(j < m - 1)
                    dp[i][j] = (dp[i - 1][j] >= 1) ? (dp[i - 1][j] - 1) / 2 : 0;
                
                if(j - 1 >= 0) 
                    dp[i][j] += (dp[i - 1][j - 1] >= 1) ? (dp[i - 1][j - 1] - 1) / 2 : 0;
            }
        }
        
        
        for(int i = 0; i < n; i++) {
            for(auto &x : dp[i]) {
                x = min((long double)1, x);
            }
        }
        
        return dp[query_row][query_glass];
    }
};