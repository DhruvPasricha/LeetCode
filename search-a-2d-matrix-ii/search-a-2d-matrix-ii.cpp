class Solution {
    
    bool search(vector<vector<int>> &A, int startRow, int startCol, int endRow, int endCol, int target) {
        
        if(startRow > endRow or startCol > endCol) return false;
        
        if(A[startRow][endCol] == target) return true;
        
        if(A[startRow][endCol] < target) return search(A, startRow + 1, startCol, endRow, endCol, target);
        
        return search(A, startRow, startCol, endRow, endCol - 1, target);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return search(matrix, 0, 0, (int)matrix.size() - 1, (int)matrix[0].size() - 1, target);
    }
};

