class Solution {
public:
    int m,n;

    bool isValid(int i, int j, vector<vector<char>>& board){
        if(i >=0 && i < m && j>=0 && j < n && board[i][j] == 'O') return true;
        return false;
    }

    void convert(vector<vector<char>>& board){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'B') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void dfs(int i, int j,vector<vector<char>>& board ){
        //check and move in all direction
        board[i][j] = 'B';

        if(isValid(i+1,j,board)){
            dfs(i+1,j,board);
        }
        if(isValid(i-1,j,board)){
            dfs(i-1,j,board);
        }
        if(isValid(i,j+1,board)){
            dfs(i,j+1,board);
        }
        if(isValid(i,j-1,board)){
            dfs(i,j-1,board);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
         n = board[0].size();
        vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
        //x,o ->connect directions
        //m region o cell ocnnet 
        // surrond x cell and none are on edge 
        // retuirn all 0 with  x place
        //ulta sochte h

        //0 boundary so andar jaate and mark krte

        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board);
            }

            if(board[i][n-1] == 'O'){
                dfs(i,n-1,board);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board);
            }

            if(board[m-1][i] == 'O'){
                dfs(m-1,i,board);
            }
        }

        convert(board);


    }
};