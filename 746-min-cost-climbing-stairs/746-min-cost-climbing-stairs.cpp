class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(3);
        dp[(n - 1) % 3] = cost[n - 1];
        dp[(n - 2) % 3] = cost[n - 2];
        for(int i = n - 3; i >= 0; --i)
            dp[i % 3] = min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + cost[i];
        return min(dp[0], dp[1]);
    }
};
