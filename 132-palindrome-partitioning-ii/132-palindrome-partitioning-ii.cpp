#define v vector

class Solution {

    v<v<bool>> isPalindrome;
    v<v<int>> dp;
    
    void init(string &s) {
        
        int n = s.size();
        isPalindrome.assign(n, v<bool>(n, false));
        
        for(int l = n - 1;l >= 0;l--) {
            for(int r = l;r < n;r++) {
                bool ans = false;
                if(l == r) 
                    ans = true;
                else if(s[l] == s[r] and (l + 1 > r - 1 or isPalindrome[l + 1][r - 1]))
                    ans = true;
                
                isPalindrome[l][r] = ans;
            }
        }
        
        dp.assign(n, vector<int> (n, -1));
    }
    
    int solve(string &s, int current, int last) {
        
        if(current == -1) {
            return (last == -1 or isPalindrome[0][last]) ? 0 : INT_MAX;   
        }
        
        int &ans = dp[current][last];
        
        if(ans != -1) 
            return ans;
        
        // don't partition
        ans = solve(s, current - 1, last);
        
        // parition if possible        
        if(isPalindrome[current][last]) {
            int ans2 = solve(s, current - 1, current - 1);
            if(ans2 != INT_MAX) {
                ans = min(ans, ans2 + 1);
            }    
        }
        
        return ans;
    }
    
    
public:
    int minCut(string &s) { 
        
        init(s);
        int n = s.size();
        
        int ans = solve(s, n - 1, n - 1);
        return ans;
    }
};