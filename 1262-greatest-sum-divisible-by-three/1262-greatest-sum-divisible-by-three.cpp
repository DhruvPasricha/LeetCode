class Solution {
    
    int dp[100000][3];
    
    int solve(vector<int> &A, int pos, int mod) {
        
        if(pos == A.size()) {
            if(mod == 0) 
                return 0;
            return -1;   
        }
        
        int &ans = dp[pos][mod];
        
        if(ans != -1) return ans;
        
        int ans1 = solve(A, pos + 1, mod);
        
        int ans2 = solve(A, pos + 1, (mod + A[pos]) % 3);
        
        
        if(ans2 >= 0)
            ans2 += A[pos];
        
        
        return ans = max({ans1, ans2});
    }
    
    
public:
    int maxSumDivThree(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(nums, 0, 0);
        return ans;
    }
};