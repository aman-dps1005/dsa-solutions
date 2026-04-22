class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,bool> rows;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(rows[board[i][j]]){
                        return false;
                    }
                    rows[board[i][j]]=true;
                }
                
            }
        }

        for(int j=0;j<9;j++){
            unordered_map<char,bool> cols;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    if(cols[board[i][j]]){
                            return false;
                    }
                    cols[board[i][j]]=true;
                }
                
            }
        }

        //for individual 3x3 grids

        map<pair<int,int>,vector<char>> grid;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(find(grid[{i/3,j/3}].begin() , grid[{i/3,j/3}].end() , board[i][j])!=grid[{i/3,j/3}].end()){
                        return false;
                    }
                    grid[{i/3,j/3}].push_back(board[i][j]);
                }
                
            }
        }

        return true;
    }
};
