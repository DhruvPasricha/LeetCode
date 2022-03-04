#define v vector

class Solution {
    
    bool safe(int x, int y, int m, int n) {
        
        return x >= 0 and x < m and y >= 0 and y < n;
    }
    
    void dfs(int x, int y, v<v<int>> &image, int initialColor) {
        
        image[x][y] = -1;
        
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        
        for(int i = 0; i < 4; i++) {
            
            int x_ = x + dx[i];
            int y_ = y + dy[i];
            
            if(safe(x_, y_, image.size(), image[0].size()) and image[x_][y_] == initialColor)
                dfs(x_, y_, image, initialColor);
        }
        
    }
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int initialColor = image[sr][sc];
        
        dfs(sr, sc, image, initialColor);
        
        for(auto &row : image) {
            for(auto &cell : row) {
                cell = (cell == -1) ? newColor : cell;
            }
        }
        
        return image;
    }
};