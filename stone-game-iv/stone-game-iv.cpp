class Solution {
    
    int dp[100001];
public:
    
    int solve(int target){
        
        if(target == 0) return false;
        int &ans = dp[target];
        if(ans != -1) return ans;
        for(int i = 1;i * i <= target;i++){
            bool canHeWin = solve(target - i * i);
            if(!canHeWin) return ans = true;  
            
        }
        return ans = false;
    }
    
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        bool ans = solve(n);
        return ans;
    }
};
