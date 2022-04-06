class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n; j++) {
                
                
                int a = nums[i];
                int b = nums[j];
                
                auto idx = lower_bound(nums.begin() + j + 1, nums.end(), a + b) - nums.begin();
             
                if(idx > 0) {
                    ans += idx - j - 1;
                }
            }
        }
        
        return ans;
    }
};