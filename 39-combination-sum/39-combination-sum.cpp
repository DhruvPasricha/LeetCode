class Solution {
    vector<int> current;
    vector<vector<int>> Ans;
    int dp[31][501];
    
    bool solve(vector<int> &A, int pos, int target) {
        
        if(target < 0) 
            return false;
        
        if(pos == A.size()) {
            if(target == 0) {
                Ans.push_back(current);            
            }
            return target == 0;
        }
        
        if(dp[pos][target] == 0)
            return false;
    
        bool ans1 = solve(A, pos + 1, target);
        
        current.push_back(A[pos]);
        bool ans2 = solve(A, pos, target - A[pos]);
        current.pop_back();
        
        return dp[pos][target] = ans1 | ans2;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        memset(dp, -1, sizeof(dp));
        
        solve(candidates, 0, target);
        
        return Ans;
    }
};