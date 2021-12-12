class Solution {
    
    int64_t mod = 1e9 + 7;
    int64_t dp[5001][7][16];
public:
    
    int64_t solve(int n, int prev, int cons, vector<int> &rollMax){
        
        if(n == 0){
            return 1;
        }
        int64_t &ans = dp[n][prev][cons];
        if(ans != -1) return ans;
        ans = 0;
        for(int i = 0;i < 6;i++){
            
            if(prev == i){
                if(cons + 1 <= rollMax[i]){
                    ans = (ans + solve(n - 1, i, cons + 1, rollMax)) % mod;
                }
            }else{
                ans = (ans + solve(n - 1, i, 1, rollMax)) % mod;
            }
        }
        return ans;
    }
    
    
    
    int dieSimulator(int n, vector<int>& rollMax) {
        
        memset(dp, -1, sizeof(dp));
        int64_t ans = solve(n, 6, 0, rollMax);
        return ans;
    }
};




