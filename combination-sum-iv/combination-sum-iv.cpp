class Solution {
int dp[1000];
public:
    
    int solve(int target, vector<int>&nums){
        
        if(target == 0) return 1;
        
        int &ans = dp[target];
        if(ans != -1) return ans;
        
        ans = 0;
        
        for(int &x : nums){
            if(x > target) return ans;
            ans += solve(target - x, nums);
        }
        
        return ans;
    }
    
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        int ans = solve(target, nums);
        return ans;
    }
};
