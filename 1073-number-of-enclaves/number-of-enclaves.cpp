class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ///0 sea and 1 land
        vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        //land cells where we can not

        //1 lelo
        queue<pair<int,int>>q;

        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 1){
                grid[i][0] = 0;
                q.push({i,0});
            }
            if(grid[i][n-1] == 1){
                grid[i][n-1] = 0;
                q.push({i,n-1});
            }
        }
        for(int j = 0 ; j < n ; j++){
            if(grid[0][j] == 1){
                grid[0][j] = 0;
                q.push({0,j});
            }
            if(grid[m-1][j] == 1){
                grid[m-1][j] = 0;
                q.push({m-1,j});
            }
        }

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();q.pop();
                int x = top.first;
                int y = top.second;

                for(auto &dir:directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(nx>=0 && nx < m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 0;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};