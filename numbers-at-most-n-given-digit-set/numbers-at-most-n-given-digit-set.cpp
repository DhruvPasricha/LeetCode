class Solution {
    int dp[10][2][2];
public:
    
    int solve(string &s, int pos, bool tight, bool lead, vector<int> &digits){
        
        if(pos == s.length()){
            return 1;
        }
        int &ans = dp[pos][tight][lead];
        if(ans != -1) return ans;
        ans = 0;
        int ub = (tight) ? s[pos] - '0' : 9;
        
        if(lead){
            ans += solve(s, pos + 1, false, true, digits);    
        }
        
        if(not tight){
            for(int d : digits) ans += solve(s, pos + 1, false, false, digits);
        }else{
            for(int d : digits){
                if(d < ub) ans += solve(s, pos + 1, false, false,  digits);
                else if(d == ub) ans += solve(s, pos + 1, tight, false, digits);
            }
        }
        
        return ans;
    }
    
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string s = to_string(n);
        vector<int> A;
        for(string &d : digits) A.push_back(stoi(d));
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, 0, true, true,  A) - 1;
        return ans;
    }
};