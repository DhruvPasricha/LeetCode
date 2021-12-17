#define v vector
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 0;
        v<v<int>> dp(n + 1, v<int> (m + 1));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                
                if(matrix[i-1][j-1] == '0') continue;
                
                int mx = min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]});
                
                dp[i][j] = 1 + mx;
                
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};