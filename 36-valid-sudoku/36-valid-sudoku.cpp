class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> box[3][3];
        
        for(int i = 0;i < 9;i++) {
            
            for(int j = 0;j < 9;j++) {
                
                int current = board[i][j];
                
                if(current == '.')
                    continue;
                
                if(row[i].count(current) or col[j].count(current) or box[i/3][j/3].count(current))
                    return false;
                
                row[i].insert(current);
                col[j].insert(current);
                box[i / 3][j / 3].insert(current);
            }
        }
        
        return true;
    }
};