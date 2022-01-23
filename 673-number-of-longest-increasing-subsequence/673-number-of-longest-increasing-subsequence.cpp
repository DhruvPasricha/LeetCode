class Solution {
    #define v vector
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        v<int> LIS(n, -1);
        v<int> dp(n, 0);
        
        for(int i = 0;i < n;i++) {
            
            int mx = 0;
            for(int j = i - 1;j >= 0;j--) 
                if(nums[j] < nums[i]) 
                    mx = max(mx, LIS[j]);
            
            LIS[i] = mx + 1;
            
            for(int j = i - 1;j >= 0;j--) 
                if(nums[j] < nums[i] and LIS[j] == mx) 
                    dp[i] += dp[j];
            
            dp[i] = max(1, dp[i]);
        }
            
        int lis = *max_element(LIS.begin(), LIS.end());
        int ans =  0;
        
        for(int i = 0;i < n;i++)
            if(LIS[i] == lis) 
                ans += dp[i];
        
        return ans;
    }
};
