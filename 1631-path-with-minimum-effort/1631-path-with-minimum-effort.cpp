class Solution {
    
    bool good(vector<vector<int>> &A, int k) {
        
        int m = A.size();
        int n = A[0].size();
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        queue<pair<int,int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while(q.size()) {
            
            
            auto [x, y] = q.front();
            q.pop();
            
            visited[x][y] = true;
            
            
            for(int i = 0;i < 4;i++) {
                
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                
                if(x_ < 0 or y_ < 0 or x_ >= m or y_ >= n)
                    continue;
                
                if(visited[x_][y_])
                    continue;
                
                if(abs(A[x_][y_] - A[x][y]) > k)
                    continue;
                
                q.push({x_, y_});
                visited[x_][y_] = true;
                
            }
        }
        
        return visited[m - 1][n - 1];
    }
    
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        
        int l = -1;
        int r = 2 * 2e6 + 100;
        
        
        while(r - l > 1) {
            
            int m = (l + r) / 2;
            
            if(good(heights, m))
                r = m;
            else
                l = m;
        }
        
        
        return r;
        
    }
};
