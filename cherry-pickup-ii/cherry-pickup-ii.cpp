class Solution {
    
    int dp[71][71][71];
public:
    
    bool safe(int x, int n){
        return x >= 0 and x < n;
    }
    
    int solve(vector<vector<int>> &grid, int x, int y1, int y2){
        
        if(!safe(y1, grid[0].size()) or !safe(y2, grid[0].size())) return INT_MIN;
        
        if(x == grid.size()) return 0;
        
        int &ans = dp[x][y1][y2];
        if(ans != -1) return ans;
        
        ans = grid[x][y1];
        if(y1 != y2) ans += grid[x][y2];
        
        
        int choices[] = {-1, 0, 1};
        
        int cur = 0;            
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                int y1_ = y1 + choices[i];
                int y2_ = y2 + choices[j];
                cur = max(cur, solve(grid, x + 1, y1_, y2_));
            }
        }
        ans += cur;
        return ans;        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));    
        int ans = solve(grid,0, 0, (int)grid[0].size() - 1);
        return ans;
    }
};
