class Solution {
public:
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m;
    int n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
         // Pacific: top row
        for (int j = 0; j < n; j++)
            dfs(heights, 0, j, pacific);

        // Pacific: left column
        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, pacific);

        // Atlantic: bottom row
        for (int j = 0; j < n; j++)
            dfs(heights, m - 1, j, atlantic);

        // Atlantic: right column
        for (int i = 0; i < m; i++)
            dfs(heights, i, n - 1, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, int r, int c,vector<vector<bool>> &visited) {
        visited[r][c] = true;
        for (auto [dr, dc] : dir) {
            int nr = r+dr;
            int nc = c+dc;
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

            if(visited[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue;
            dfs(heights, nr, nc, visited);
        }
    }
};
