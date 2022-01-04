class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> A(numRows);
        
        for(int i = 0;i < numRows;i++) {
            A[i].assign(i + 1, 1);
            for(int j = 1;j < i;j++) 
                A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
        }
        
        return A;
    }
};
