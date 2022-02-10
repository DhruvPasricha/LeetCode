class Solution {
    
    const int64_t mod = 1e9 + 7;
    int64_t dp[100001][2];
    
    int solve(string &s, int pos, bool first, vector<int> &nextZero, vector<int> &nextOne) {
        
        int n = s.size();
        
        if(pos >= n)
            return 0;
        
        int64_t &ans = dp[pos][first];
        
        if(ans != -1) 
            return ans;
        
        ans = 0;
       
        // zero
        if(not first)
            ans = (ans + (nextZero[pos] < n) + solve(s, nextZero[pos] + 1, false, nextZero, nextOne)) % mod;
        
                   
        // one
        ans = (ans + (nextOne[pos] < n) + solve(s, nextOne[pos] + 1, false, nextZero, nextOne)) % mod;
        
        return  ans;
    }
    
    
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        
        int n = binary.size();
        vector<int> nextZero(n + 1, n);
        vector<int> nextOne(n + 1, n);
        
        for(int i = n - 1;i >= 0;i--) {
            
            nextZero[i] = nextZero[i + 1];
            nextOne[i] = nextOne[i + 1];
            
            if(binary[i] == '0')
                nextZero[i] = i;
            else
                nextOne[i] = i; 
        }
        
        memset(dp, -1, sizeof(dp));
        
        int ans = ((nextZero[0] < n) + solve(binary, 0, true, nextZero, nextOne)) % mod;
        return ans;
    }
};
