class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n - i;j++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};