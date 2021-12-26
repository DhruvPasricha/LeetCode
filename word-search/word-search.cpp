#define v vector
class Solution {
public:
    
    bool safe(int x,int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    
    bool solve(v<v<char>> &board, int x, int y, string &s, int pos, v<v<bool>> &visited) {
        
        if(s[pos] != board[x][y]) return false;
        
        if(pos + 1 == s.length()) return true;
        
        visited[x][y] = true;
        
        int n = board.size();
        int m = board[0].size();
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};
        
        for(int i = 0;i < 4;i++) {
            int x_ = x + dx[i];
            int y_ = y + dy[i];
            
            if(safe(x_, y_, n, m) and !visited[x_][y_]) {
                bool ans = solve(board, x_, y_, s, pos + 1, visited);
                if(ans) return true;
            }
        }
        
        visited[x][y] = false;
        
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        
        v<v<bool>> visited(n, v<bool>(m, false));
        
        for(int i = 0;i < n;i++) {
            for(int j  = 0;j < m;j++) {
                if(solve(board, i, j, word, 0, visited)) return true;
            }
        }
        
        return false;
    }
};