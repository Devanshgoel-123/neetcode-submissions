class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int m = grid.size();
        int fresh = 0;
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i< m; i++) {
            for(int j=0; j<n;j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1 ) fresh++;
            }
        }
        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                auto [r, c] = q.front();
                q.pop();
                for(auto [dr, dc]:dir) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;
                grid[nr][nc] = 2;
                fresh--;
                q.push({nr, nc});
                }
            size--;
            }
            if (!q.empty()) time++;
        }
        return fresh == 0 ? time : -1;
    }   
};
