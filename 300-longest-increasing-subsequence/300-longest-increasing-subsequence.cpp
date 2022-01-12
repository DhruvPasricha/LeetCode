class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> LIS;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            
            if(LIS.empty() or LIS.back() < nums[i]) {
                LIS.push_back(nums[i]);
            } else {
                auto itr = lower_bound(LIS.begin(), LIS.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return LIS.size();
    }
};