class Solution {
public:
    bool winnerSquareGame(int n) {
        
        // dp[i] : can anyone win starting from i         
        
        vector<int> dp(n + 1, false);
        dp[0] = false;
        
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j * j <= i;j++) {
                int stonesRemoved = j * j;
                if(not dp[i - stonesRemoved]) {
                    dp[i] = true;
                    break;
                }
             }
        }
        
        return dp[n];
    }
};