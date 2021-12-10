class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char, int> row[9], col[9], box[3][3];
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                char current = board[i][j]; 
                if(current == '.') continue;
                bool exists = (row[i][current] or col[j][current] or box[i/3][j/3][current]);
                if(exists) return false;              
                row[i][current]++;
                col[j][current]++;
                box[i/3][j/3][current]++;
            }
        }
        return true;
    }
};