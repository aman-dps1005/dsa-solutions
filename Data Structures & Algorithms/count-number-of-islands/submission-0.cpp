class Solution {
public:
    void markIsland(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = 1;

        markIsland(grid, visited, i-1, j);
        markIsland(grid, visited, i+1, j);
        markIsland(grid, visited, i, j-1);
        markIsland(grid, visited, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    markIsland(grid,visited,i,j);
                }
            }
        }

        return count;
    }
};
