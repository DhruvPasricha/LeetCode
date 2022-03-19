class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        
        for(int i = 0;i < n;i++) {
            ans[i].assign(i + 1, 1);
            
            for(int j = 1; j < i; j++)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        
        return ans;
    }
};