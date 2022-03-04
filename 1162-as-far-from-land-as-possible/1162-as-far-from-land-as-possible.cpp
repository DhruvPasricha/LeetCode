#define v vector

class Solution {
    
    bool safe(int x, int y, int n) {
        
        return x >= 0 and x < n and y >= 0 and y < n;
    }
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        v<v<int>> dist(n, v<int>(n, INT_MAX));
    
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(q.size() > 0) {
            
            auto [x, y] = q.front();
            q.pop();
            
            
            // visit all neighbours of f
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            
            for(int i = 0;i < 4;i++) {
                
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                
                if(safe(x_, y_, n) and dist[x_][y_] == INT_MAX) {
                    
                    dist[x_][y_] = dist[x][y] + 1;
                    q.push({x_, y_});
                } 
            }
            
            
        }
        
        int ans = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                ans = max(ans, dist[i][j]);
        
        return (ans == INT_MAX or ans == 0) ? -1 : ans;
    }
};