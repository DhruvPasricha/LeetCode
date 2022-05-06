class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end());
        
        int n = envelopes.size();
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        
        int i = 0;
        while(i < n) {
            int j = i;
            while(i < n and envelopes[i][0] == envelopes[j][0]) {
                i++;
            }
            
            for(int k = i - 1; k >= j; k--) {
                auto itr = lower_bound(dp.begin(), dp.end(), envelopes[k][1]);
                *itr = envelopes[k][1];
            }
        }
            
        for(int i = n; i >= 0; i--)
            if(dp[i] != INT_MAX)
                return i;
        
        return -1;
    }
    
    
};