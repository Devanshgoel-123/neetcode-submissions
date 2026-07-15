class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea =0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
       for(int i=0; i<m; i++) {
        for(int j=0; j< n; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int area = checkIsland(grid, visited, i,j);
                maxArea = max(area, maxArea);
            }
        }
       }
       return maxArea;
    }
    int checkIsland(vector<vector<int>>& grid,vector<vector<int>> &visited,int r, int c) {
       int m = grid.size();
       int n = grid[0].size();
       int count=0;
       if( r< 0 || c< 0 || r > m-1 || c > n-1)  return 0;
       if (visited[r][c] || grid[r][c] == 0)  return 0;
        visited[r][c] = 1;
        // Explore all four directions
        count += checkIsland(grid, visited, r + 1, c);
        count +=checkIsland(grid, visited, r - 1, c);
        count +=checkIsland(grid, visited, r, c + 1);
        count +=checkIsland(grid, visited, r, c - 1);
        return 1+count;
    }
};
