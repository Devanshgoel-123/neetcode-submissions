class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowCheck(9, vector<bool> (9, false));
        vector<vector<bool>> colCheck(9, vector<bool> (9, false));
        vector<vector<bool>> boxCheck(9, vector<bool> (9, false));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                if(rowCheck[board[i][j] - '1'][i] == true) return false;
                rowCheck[board[i][j] - '1'][i] = true;

                if(colCheck[board[i][j] - '1'][j] == true) return false;
                colCheck[board[i][j] - '1'][j] = true;

                if(boxCheck[board[i][j] - '1'][3 * (i / 3) + j / 3] == true) return false;
                boxCheck[board[i][j] - '1'][3 * (i / 3) + j / 3] = true;
            }
        }
        return true;
    }
};
