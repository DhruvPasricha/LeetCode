class Solution {
    
    int dp[10][2][1 << 10][2];
    
    int solve(string &s, int pos, bool tight, int taken, bool lead) {
        
        if(pos == s.size())
            return 1;
        
        int lb = 0;
        int ub = (tight) ? s[pos] - '0' : 9;
        
        int &ans = dp[pos][tight][taken][lead];
        
        if(ans != -1)
            return ans;
        
        ans = 0;
        
        for(int i = lb; i <= ub; i++) {
            
            if((1 << i) & taken) 
                continue;
            
            bool newTight = tight and i == ub;
            bool newLead = lead and i == 0;
            int newTaken = (newLead) ? taken : taken | (1 << i);
            
            ans += solve(s, pos + 1, newTight, newTaken, newLead);
            
        }
        
        return ans;
        
    }
    
public:
    int numDupDigitsAtMostN(int n) {
        
        memset(dp, -1, sizeof(dp));
        
        auto s = to_string(n);
        
        int ans = solve(s, 0, true, 0, true) - 1;
        return n - ans;
        
    }
};