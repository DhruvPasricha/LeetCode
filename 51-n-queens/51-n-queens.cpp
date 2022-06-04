class Solution {
    
    vector<vector<string>> ans;
    vector<string> cur;
    int n;
    
    void init() {
        string temp;
        for(int i = 0; i < n; ++i) temp += '.';
        cur.resize(n, temp); 
    }
    
    
    bool canPlace(int x, int y) {
        
        // up
        for(int i = x, j = y; i >= 0; i--)
            if(cur[i][j] == 'Q')
                return false;
        
        // diag1
        for(int i = x, j = y; i >= 0 and j >= 0; i--, j--)
            if(cur[i][j] == 'Q')
                return false;
        
        // diag2
        for(int i = x, j = y; i >= 0 and j < n; i--, j++)
            if(cur[i][j] == 'Q')
                return false;
        
        return true;
    }
    
    void solve(int row) {
        
        if(row == n) {
            ans.push_back(cur);
            return;
        }
        
        for(int j = 0; j < n; ++j) {
            
            if(canPlace(row, j)) {
                cur[row][j] = 'Q';
                solve(row + 1);
                cur[row][j] = '.';
            }
            
        }
        
        
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        init();
        solve(0);
        return ans;
    }
};