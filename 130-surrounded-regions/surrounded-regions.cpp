class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        //let try with extra space
        vector<vector<char>>temp(m,vector<char>(n,'X'));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O' ){
                temp[i][0] = 'O';
                q.push({i,0});
            }
            if( board[i][n-1] == 'O'){
                temp[i][n-1] ='O';
                q.push({i,n-1});
            }
        }

         for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O' ){
                temp[0][j] = 'O';
                q.push({0,j});
            }
            if( board[m-1][j] == 'O'){
                temp[m-1][j] ='O';
                q.push({m-1,j});
            }
        }

        vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;

                for(auto &dir : directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(nx >=0 && nx < m && ny >=0 && ny < n && board[nx][ny] == 'O' && temp[nx][ny]!= 'O'){
                        temp[nx][ny] = 'O';
                        q.push({nx,ny});
                    }

                }
            }
        }

        board = temp;
    }
};