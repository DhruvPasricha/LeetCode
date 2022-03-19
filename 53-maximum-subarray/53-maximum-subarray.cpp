class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = nums[0];
        int cur = nums[0];
        
        
        for(int i = 1; i < n; i++) {
            cur = max(cur + nums[i], nums[i]);
            ans = max(ans, cur);
        }
        
        return ans;
    }
};