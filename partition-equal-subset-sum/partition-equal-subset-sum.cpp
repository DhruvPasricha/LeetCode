class Solution {
    int dp[201][20001];
public:
    
    
    bool solve(vector<int> &A, int n, int target){
        
        if(target < 0) return false;
        
        if(n == 0) return target == 0;
        
        int &ans = dp[n][target];
        
        if(ans != -1) return ans;
        
        return ans = solve(A, n - 1, target - A[n - 1]) or solve(A, n - 1, target);
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
               
        int sum = 0;
        
        for(int num : nums) sum += num;
        
        if(sum & 1) return false;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, nums.size(), sum / 2);
    }
};