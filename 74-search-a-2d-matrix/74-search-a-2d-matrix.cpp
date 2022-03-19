class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int startCol = 0;
        int startRow = 0;
        
        int endRow = matrix.size() - 1;
        int endCol = matrix[0].size() - 1;
        
        while(startRow <= endRow and startCol <= endCol) {
            
            int topRight = matrix[startRow][endCol];
            
            if(topRight == target)
                return true;
            
            if(topRight < target)
                startRow++;
            else
                endCol--;
        }
        
        return false;
    }
};