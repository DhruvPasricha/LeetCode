class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        for(int i = 0;i < n;i++) {
            int mx = nums[i];
            int mn = nums[i];
            for(int j = i;j >= 0;j--) {
                mx = max(nums[j], mx);
                mn = min(nums[j], mn);
                ans += (int64_t)(mx - mn);
            }
        }
        return ans;
    }
};