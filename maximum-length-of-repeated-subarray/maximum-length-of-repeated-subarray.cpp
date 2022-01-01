class Memo {
public:
    int dp[1001][1001][2];
    Memo(){
        memset(dp, -1, sizeof(dp));
    }
};
class Solution {
    
    int solve(vector<int> &A, vector<int> &B, int n1 ,int n2, bool cont, Memo &memo) {
        
        if(n1 == 0 or n2 == 0) return 0;
        int &ans = memo.dp[n1][n2][cont];
        if(ans != -1) return ans;
        ans = 0;
        if(not cont) {
            int ans1 = solve(A, B, n1 - 1, n2, false, memo);
            int ans2 = solve(A, B, n1, n2 - 1, false, memo);
            ans = max(ans1, ans2);
        }
        if(A[n1-1] == B[n2-1]) {
            int ans3 = solve(A, B, n1 - 1, n2 - 1, true, memo) + 1;
            ans = max(ans, ans3);
        }
        return ans;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        Memo memo;
        int ans = solve(nums1, nums2, nums1.size(), nums2.size(), false, memo);
        return ans;
    }
};