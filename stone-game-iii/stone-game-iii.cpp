class Solution {
    int dp[50001];
    public:
    int solve(vector<int> &A, int pos){
        
        if(pos >= A.size()) return 0;
        
        int &ans = dp[pos];
        if(ans != -1) return ans;
        ans = INT_MIN;
        int cur = 0;
        
        for(int i = 0;i < 3;i++){
            if(pos + i == A.size()) break;
            cur += A[pos + i];
            ans = max(ans, cur - solve(A, pos + i + 1));
            
        }
        
        return ans;
    }
    
    
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(stoneValue, 0);
        
        if(ans > 0) return "Alice";
        if(ans == 0) return "Tie";
        return "Bob"; 
    }
};