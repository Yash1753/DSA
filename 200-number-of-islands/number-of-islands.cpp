class Solution {
public:
    int m,n;
    vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>&grid){
        grid[i][j] = 0;

        for(auto &dir : directions){
            int nx = i + dir.first;
            int ny = j + dir.second;

            if(nx>=0 && nx < m && ny>=0 && ny < n && grid[nx][ny] == '1' ){
                
                dfs(nx,ny,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};