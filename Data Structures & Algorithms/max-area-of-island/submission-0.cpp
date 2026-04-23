class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==0 || visited[i][j]==1){
            return 0;
        }

        visited[i][j]=1;
        int count=1;

        //up
        count+=solve(grid,visited,i-1,j);
        //down
        count+=solve(grid,visited,i+1,j);
        //right
        count+=solve(grid,visited,i,j+1);
        //left
        count+=solve(grid,visited,i,j-1);

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxCount=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    int soln=solve(grid,visited,i,j);
                    maxCount=max(soln,maxCount);
                }
            }
        }

        return maxCount;
    }
};
