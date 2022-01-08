class Solution {
    vector<vector<int>> *gridAdd;
    int n,m;
    int dp[70][70][70];
    
    bool safe(int j) {
        return j >= 0  and j < m;
    }
    
    int solve(int row, int prevCol1, int prevCol2) {
        
        auto &grid = *gridAdd;
        
        if(row == n) return 0;
        
        int &ans = dp[row][prevCol1][prevCol2];
        if(ans != -1) return ans;
        
        int start1 = prevCol1 - 1;
        int end1 = prevCol1 + 1;
        
        int start2 = prevCol2 - 1;
        int end2 = prevCol2 + 1;
        
        ans = INT_MIN;
        for(int i = start1;i <= end1;i++) {
            for(int j = start2; j <= end2;j++) {
                if(i == j or not safe(i) or not safe(j)) continue;
                int cur = solve(row + 1, i, j);
                if(cur != INT_MIN) cur += grid[row][i] + grid[row][j];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this -> gridAdd = &grid;
        this -> n = grid.size();
        this -> m = grid[0].size();
        memset(dp, -1 ,sizeof(dp));
        
        int ans = solve(1, 0, m - 1) + grid[0][0] + grid[0][m - 1];
        return ans;
    }
};