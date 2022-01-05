class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
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
};