class Solution {
    
    int dp[1001][1001];
    
    
    int solve(string &a, string &b, int n, int m)
    {    
       if(n == 0)
            return m;
        
        if(m == 0)
            return n;
        
        int &ans = dp[n][m];
        
        if(ans != -1)
            return ans;
        
        if(a[n - 1] == b[m - 1])
            return ans = 1 + solve(a, b, n - 1, m - 1);
        
        int ans1 = 1 + solve(a, b, n - 1, m);
        int ans2 = 1 + solve(a, b, n, m - 1);
        
        return ans = min(ans1, ans2);
        
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        
        memset(dp, -1, sizeof(dp));
        int len = solve(str1, str2, str1.size(), str2.size());
        
        
        string ans = "";
        
        int n = str1.size();
        int m = str2.size();
        
        while(len > 0) {
            
            if(m == 0) {
                ans += str1[n - 1];
                n--;
            }else if(n == 0) {
                ans += str2[m - 1];
                m--;
            }else{
                if(str1[n - 1] == str2[m - 1]) {
                    ans += str1[n - 1];
                    n--;
                    m--;
                } else if(dp[n][m] == 1 + dp[n - 1][m]) {
                    ans += str1[n - 1];
                    n--;
                } else{
                    ans += str2[m - 1];
                    m--;
                }
            }
            
            len--;
            
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};


