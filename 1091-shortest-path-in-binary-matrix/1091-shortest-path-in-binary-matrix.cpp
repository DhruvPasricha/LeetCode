#define v vector
class Solution {
    
    
    bool safe(int x, int y, int n) {
        
        return x >= 0 and x < n and y >= 0 and y < n;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        v<v<int>> dist(n, v<int>(n, INT_MAX));
    
        queue<pair<int, int>> q;
        
        if(grid[0][0] == 0) {
            q.push({0, 0});
            dist[0][0] = 1;
        }
        
        while(q.size() > 0) {
            
            auto [x, y] = q.front();
            q.pop();
            
            
            // visit all neighbours of f
            int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
            int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
            
            for(int i = 0;i < 8;i++) {
                
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                
                if(safe(x_, y_, n) and grid[x_][y_] == 0 and dist[x_][y_] == INT_MAX) {
                    
                    dist[x_][y_] = dist[x][y] + 1;
                    q.push({x_, y_});
                } 
            }
            
            
        }
        
        return dist[n - 1][n - 1] == INT_MAX ? -1 : dist[n - 1][n - 1];
    }
};