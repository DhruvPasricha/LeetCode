class Solution {
int dp[1000][1000];
public:
    
    int solve(int pos, int target, vector<int>&nums){
        
        if(target == 0){
            return 1;
        }
        
        int &ans = dp[pos][target];
        if(ans != -1) return ans;
        ans = 0;
        
        for(int &x : nums){
            if(x > target){
                break;
            }
            ans += solve(pos + 1, target - x, nums);
        }
        
        return ans;
    }
    
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, target, nums);
        return ans;
    }
};
