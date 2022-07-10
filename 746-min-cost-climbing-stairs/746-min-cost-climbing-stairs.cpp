class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1];
        dp[n - 2] = cost[n - 2];
        for(int i = n - 3; i >= 0; --i)
            dp[i] = min(dp[i + 1], dp[i + 2]) + cost[i];
        return min(dp[0], dp[1]);
    }
};