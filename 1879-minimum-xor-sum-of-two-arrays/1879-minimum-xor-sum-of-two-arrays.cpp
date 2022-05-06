class Solution {
    
    int dp[15][1 << 15];
    int solve(vector<int> &A, vector<int> &B, int n, int mask) {
        
        if(n == 0)
            return 0;
        
        int &ans = dp[n][mask];
        
        if(ans != -1)
            return ans;
        
        ans = INT_MAX;
        for(int i = 0; i < B.size(); i++) {
            if(mask & (1 << i))
                continue;
            
            ans = min(ans, (A[n - 1] ^ B[i]) + solve(A, B, n - 1, mask | (1 << i)));
        }
        
        return ans;
        
    }
    
    
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums1, nums2, nums1.size(), 0);
        return ans;
    }
};
