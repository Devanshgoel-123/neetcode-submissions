class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
     vector<vector<int>> visited(m, vector<int>(n, 0));
       int count=0;
       for(int i=0; i<m; i++) {
        for(int j=0; j< n; j++) {
            if(grid[i][j] == '1' && !visited[i][j]) {
                count++;
                checkIsland(grid, visited, i,j);
            }
        }
       }
       return count;
    }

    void checkIsland(vector<vector<char>>& grid,vector<vector<int>> &visited,int r, int c) {
       int m = grid.size();
       int n = grid[0].size();
       if( r< 0 || c< 0 || r > m-1 || c > n-1)  return;
       if(visited[r][c]) return;
        visited[r][c] = 1;
        if(grid[r][c] == '0') return;
        if(r != m-1 && grid[r+1][c] == '1') {
           checkIsland(grid, visited,r+1,c);
        }
        if(c!= n-1 && grid[r][c+1] == '1') {
           checkIsland(grid, visited,r,c+1);
        }
        if(r!= 0 && grid[r-1][c]  == '1') {
             checkIsland(grid, visited,r-1,c);
        }
        if(c != 0 && grid[r][c-1] == '1') {
           checkIsland(grid, visited,r,c-1);
        }
       return;
    }
 };
