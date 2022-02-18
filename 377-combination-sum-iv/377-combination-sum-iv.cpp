class Solution {
    
    int dp[1001];
    
    int solve(vector<int> &A, int target) {
        
        if(target == 0)
            return 1;
        
        int &ans = dp[target];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
        
        for(int x : A)
            if(x > target)
                break;
            else
                ans += solve(A, target - x);
    
        return ans;
        
    }
    
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(dp, -1, sizeof(dp));
        
        sort(nums.begin(), nums.end());
        
        int ans = solve(nums, target);
        
        return ans;
    }
};