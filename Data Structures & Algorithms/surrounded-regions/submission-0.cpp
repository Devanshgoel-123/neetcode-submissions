class Solution {
public:
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m;
    int n;
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        set<pair<int,int>> st;
        vector<vector<int>> visitedArr(m, vector<int>(n,0));
        // top row
        for (int j = 0; j < n; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j,st,visitedArr);
        }

        // left column
        for (int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0,st,visitedArr);
        }
           

        // bottom row
        for (int j = 0; j < n; j++) {
            if(board[m-1][j] == 'O') dfs(board, m - 1, j,st,visitedArr);
        }
        
        // right column
        for (int i = 0; i < m; i++) {
            if(board[i][n-1] == 'O') dfs(board, i, n - 1,st,visitedArr);
        }

         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if(st.contains({i,j})) board[i][j] = 'O';
                    else{
                        board[i][j] = 'X';
                    }
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, int r, int c,set<pair<int, int>> &st,vector<vector<int>> &visitedArr ) {
        visitedArr[r][c] = 1;
        st.insert({r,c});
        for (auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(board[nr][nc] == 'X' || visitedArr[nr][nc]) continue;
            dfs(board, nr, nc, st, visitedArr);
        }
    }
};
