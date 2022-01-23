class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = min element at which an increasing subsequence ends having length = i
        vector<int> dp(n + 1, INT_MAX);         
        dp[0] = INT_MIN;
        int ans =  0;
        for(int &num : nums) {
            int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            ans = max(ans, pos);
            dp[pos] = num;
        }
        return ans;
    }
};