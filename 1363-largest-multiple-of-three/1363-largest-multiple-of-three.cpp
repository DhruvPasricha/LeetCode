class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        
        sort(digits.begin(), digits.end(), greater<int>());
        
        int n = digits.size();
        
        int dp[n + 1][3];
        
        for(int pos = n; pos >= 0; pos--) {
            
            for(int mod = 0; mod < 3; mod++) {
                
                int &ans = dp[pos][mod];
        
                if(pos == n) {
                    if(mod == 0)
                        ans = 0;
                    else
                        ans = -1;
                    
                } else {
                    
                    int ans1 = dp[pos + 1][mod];
                    int ans2 = dp[pos + 1][(mod + digits[pos]) % 3];
                    
                    if(ans2 >= 0)
                        ans2 += 1;
                    
                    ans = max(ans1, ans2);
                    
                }
                
            }
               
        }
        
        string ans = "";
        int mod = 0;
        
        for(int i = 0;i < n;i++) {
            
            if(dp[i][mod] > 0 and dp[i][mod] == 1 + dp[i + 1][(mod + digits[i]) % 3]) {
                ans += (char)(digits[i] + '0');
                mod = (mod + digits[i]) % 3;
            }
            
        }
        
        if(ans.size() > 0 and ans[0] == '0')
            ans = "0";
        
        return ans;
    }
};