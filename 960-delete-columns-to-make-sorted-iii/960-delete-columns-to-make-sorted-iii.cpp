class Solution {
    
    int dp[102][102];
    
    bool good(vector<string> &A, int start, int end) {
        
        int n = A.size();
        
        if(start < end) {
            
            for(int i = 0;i < n;i++) {
                if(A[i][start] > A[i][end])
                    return false;
            }    
            
        }
        
        return true;
        
    }
    
    int solve(vector<string> &A, int pos, int prev) {
        
        if(pos == A[0].size())
            return 0;
        
        int &ans = dp[pos][prev];
        
        if(ans != -1)
            return ans;
        
        // deleting this
        ans = 1 + solve(A, pos + 1, prev);
        
        // choosing this if possible
        if(good(A, prev, pos)) {
            int ans2 = solve(A, pos + 1, pos);
            ans = min(ans2, ans);
        }
        
        return ans;
        
    }
    
public:
    int minDeletionSize(vector<string>& strs) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans  = solve(strs, 0, 101);
        
        return ans;
    }
};
