class Solution {
    int dp[13][10001];
public:
    
    int solve(vector<int> &A, int pos, int target){
        
        if(target == 0) return 0;
        if(pos == A.size() or target < 0) return INT_MAX;
        
        int &ans = dp[pos][target];
        if(ans != -1) return ans;
        
        int ans1 = solve(A, pos + 1, target);
        int ans2 = solve(A, pos, target - A[pos]);
        if(ans2 != INT_MAX) ans2++;
        return ans = min(ans1, ans2);
    }
    
    
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1,sizeof(dp));
        int ans = solve(coins, 0, amount);
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};