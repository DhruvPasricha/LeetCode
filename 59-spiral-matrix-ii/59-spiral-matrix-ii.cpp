class Solution {
    
    vector<vector<int>> Ans;
    int placeValue;
    
    
    void solve(int startRow, int endRow, int startCol, int endCol) {
        
        if(startRow > endRow or startCol > endCol)
            return;
        
        if(startRow == endRow) {
            
            for(int j = startCol; j <= endCol; j++)
                Ans[startRow][j] = ++placeValue;
            
        } else if(startCol == endCol) {
            
            for(int i = startRow; i <= endRow; i++)
                Ans[i][startCol] = ++placeValue;
            
        } else {
            
            // left to right
            for(int j = startCol; j <= endCol; j++)
                Ans[startRow][j] = ++placeValue;
            
            // top to bottom
            for(int i = startRow + 1; i <= endRow; i++)
                Ans[i][endCol] = ++placeValue;
                
            // right to left
            for(int j = endCol - 1; j >= startCol; j--)
                Ans[endRow][j] = ++placeValue;
            
            
            // bottom to top
            for(int i = endRow - 1; i >= startRow + 1; i--)
                Ans[i][startCol] = ++placeValue;
            
            
            solve(startRow + 1, endRow - 1, startCol + 1, endCol - 1);
            
            
        }
        
    }
    
public:
    vector<vector<int>> generateMatrix(int n) {
        
        Ans.assign(n, vector<int>(n));
        
        placeValue = 0;
        solve(0, n - 1, 0, n - 1);
        
        return Ans;
    }
};