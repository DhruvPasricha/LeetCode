class Solution {
    int dp[1001][1001];
public:
    
    int solve(string &s, string &t, int n1, int n2){
            
        if(n2 == 0) return 1;
        if(n1 == 0) return 0;
        
        int &ans = dp[n1][n2];
        if(ans != -1) return ans;
        int ans1 = solve(s, t, n1 - 1, n2);
        int ans2 = (s[n1 - 1] == t[n2 - 1]) ? solve(s, t, n1 - 1, n2 - 1) : 0;
        
        return ans = ans1 + ans2;
        
    }
    int numDistinct(string s, string t) {
        
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, t, s.length(), t.length());
        return ans;
    }
};