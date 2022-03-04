class Solution {
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool safe(int x,int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    
    bool dfs(vector<vector<char>> &grid, int x,int y, vector<vector<bool>> &visited) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(not safe(x ,y ,n, m) or grid[x][y] == '0' or visited[x][y]) return false;
        
        visited[x][y] = true;
        
        for(int i = 0;i < 4;i++) {
            int x_ = x + dx[i];
            int y_ = y + dy[i];
            dfs(grid, x_, y_, visited);
        }
        
        return true;
        
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) {
                ans += dfs(grid, i, j, visited);
            }
        }
        return ans;
    }
};