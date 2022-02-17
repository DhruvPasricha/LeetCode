class Solution {
    
    vector<int> current;
    vector<vector<int>> Ans;
    
    void solve(int digit, int k, int n) {
        
        if(digit == 10) {
            if(n == 0 and k == 0)
                Ans.push_back(current);
            return;
        }
        
        // not choosing digit
        solve(digit + 1, k, n);
        
        // choosing digit
        current.push_back(digit);
        solve(digit + 1, k - 1, n - digit);
        current.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        solve(1, k, n);
        return Ans;
    }
};