class Solution {
    
    void rotate(int &a, int &b, int &c, int &d) {
        int temp = a;
        a = d;
        d = c;
        c = b;
        b = temp;
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        int startCol = 0;
        int startRow = 0;
        int endCol = n - 1;
        int endRow = n - 1;
        
        
        while(startRow < endRow and startCol < endCol) {
            
            int m = endRow - startRow + 1;
            
            
            for(int i = 0;i < m - 1; i++) {
                
                int &element1 = matrix[startRow][startCol + i];
                int &element2 = matrix[startRow + i][endCol];
                int &element3 = matrix[endRow][endCol - i];
                int &element4 = matrix[endRow - i][startCol];
                
                rotate(element1, element2, element3, element4);
            }
            
            startRow++;
            startCol++;
            endRow--;
            endCol--;
        }
    }
};