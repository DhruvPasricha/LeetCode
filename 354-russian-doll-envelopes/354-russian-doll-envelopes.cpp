class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &A, vector<int> &B){
            
            if(A[0] != B[0])
                return A[0] < B[0];
            
            return A[1] > B[1];
            
        });
        
        int n = envelopes.size();
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        
        for(int i = 0;i < n;i++){
            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            *itr = envelopes[i][1];
        }
            
        for(int i = n; i >= 0; i--)
            if(dp[i] != INT_MAX)
                return i;
        
        return -1;
    }
    
    
};