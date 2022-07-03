class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 2; ++j) {
                bool isSmallerNeeded = (j == 0);
                for(int k = i - 1; k >= 0; --k) {
                    if(nums[i] == nums[k]) continue;
                    if(isSmallerNeeded and nums[k] < nums[i]) {
                        dp[i][j] = max(dp[i][j], dp[k][1]);
                    } else if(not isSmallerNeeded and nums[k] > nums[i]) {
                        dp[i][j] = max(dp[i][j], dp[k][0]);
                    }
                }
                dp[i][j]++;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};