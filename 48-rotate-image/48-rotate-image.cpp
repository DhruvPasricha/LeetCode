class Solution { 
    // works only when matrix[i][j] is not too big
    void solve1(vector<vector<int>> &matrix){
         int n = matrix.size();
        
        for(int i = 0 ;i < n;i++) 
            for(int j = 0;j < n;j++)
                matrix[i][j] += 1000;
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                matrix[j][n - i - 1] += 2001*(matrix[i][j] % 2001);
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                matrix[i][j] = (matrix[i][j]/2001) - 1000;
        
    }
    
    void solve2(vector<vector<int>> &matrix) {
        
        int n = matrix.size();
        
        for(int i = 0;i < n;i++) 
            reverse(matrix[i].begin(), matrix[i].end());
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n - 1 - i;j++)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        solve2(matrix);
    }
};