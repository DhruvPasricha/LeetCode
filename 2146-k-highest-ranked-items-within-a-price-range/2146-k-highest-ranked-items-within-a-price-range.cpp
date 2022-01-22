struct node {
    int dist;
    int row;
    int col;
    int price;
    
};

// ye last m niklega
bool operator<(node a, node b) {
    
    if(a.dist != b.dist) return a.dist < b.dist;
    
    if(a.price != b.price) return a.price < b.price;
    
    if(a.row != b.row) return a.row < b.row;
    
    return a.col < b.col;
    
}

class Solution {
    #define v vector
    #define pii pair<int,int>
    #define ff first
    #define ss second
    
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int low = price[0];
        int high = price[1];
        
        v<v<bool>> visited(n, v<bool>(m, false));
        v<v<int>> dist(n, v<int>(m));
        
        queue<pii> q;
        
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        
        priority_queue<node> pq;
        
        
        while(q.size() > 0) {
        
            int x = q.front().ff;
            int y = q.front().ss;
            q.pop();
            
            if(grid[x][y] >= low and grid[x][y] <= high) {
                node current;
                current.row = x;
                current.col = y;
                current.dist = dist[x][y];
                current.price = grid[x][y];
                pq.push(current);
                if(pq.size() > k) pq.pop();
            }
            
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int i = 0;i < 4;i++) {
                
                int x_ = x + dx[i];
                int y_ = y + dy[i];
                
                if(x_ >= 0 and x_ < n and y_ >= 0 and y_ < m) {
                
                    
                    if(visited[x_][y_] or grid[x_][y_] == 0)
                        continue;
                    
                    visited[x_][y_] = true;
                    q.push({x_, y_});
                    dist[x_][y_] = dist[x][y] + 1;
                    
                    if(grid[x_][y_] < low or grid[x_][y_] > high)
                        continue;

                }
            }
        }
        
        v<v<int>> Ans(pq.size());
        int i = pq.size();
        i--;
        while(pq.size()) {
            auto f = pq.top();
            pq.pop();
            Ans[i] = {f.row, f.col};
            i--;
        }
        return Ans;
    }
};