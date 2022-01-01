class Solution {
    int dp[501][501];
    
    int solve(vector<int> &A, int l, int r) {
        if(l > r) return 0;
        int &ans = dp[l][r];
        if(ans != -1) return ans;
        for(int i = l;i <= r;i++) {
            // choosing ith to burst at last
            int left = solve(A, l, i - 1);
            int right = solve(A, i + 1, r);
            int cur = A[i];
            if(l - 1 >= 0) cur *= A[l - 1];
            if(r + 1 < A.size()) cur *= A[r + 1];
            ans = max(ans, cur + left + right);
        }
        return ans;
    }
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int maxCoins(vector<int>& nums) {
        return solve(nums, 0, (int)nums.size() - 1);
    }
        
};
