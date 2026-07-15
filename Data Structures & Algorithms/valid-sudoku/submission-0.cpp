class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0; i< 9;i++) {
            vector<bool> rowChecker(9, 0);
            for(int j=0; j< 9; j++) {
                if (board[i][j] == '.') continue;
                if ( rowChecker[board[i][j] - '1'] == true) return false;
                rowChecker[board[i][j] - '1'] = true;
            }
        }
        for(int i=0; i < 9;i++) {
            vector<bool> rowChecker(9, 0);
            for(int j=0; j< 9; j++) {
                if (board[j][i] == '.') continue;
                if ( rowChecker[board[j][i] - '1'] == true) return false;
                rowChecker[board[j][i] - '1'] = true;
            }
        }

       for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                vector<bool> seen(9, false);
                for (int i = boxRow; i < boxRow + 3; i++) {
                    for (int j = boxCol; j < boxCol + 3; j++) {

                        if (board[i][j] == '.') continue;

                        int num = board[i][j] - '1';

                        if (seen[num]) return false;

                        seen[num] = true;
            }
        }
    }
}
return true;
    }
};
