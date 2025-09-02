class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    
    bool isValid(int i, int j,vector<vector<char>>& grid){
        if(i>=0 && i < m && j >=0 && j <n && grid[i][j] == '1') return true;
        return false;
    }
    void dfs(int i, int j,vector<vector<char>>& grid ){
        grid[i][j] = 0;

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(isValid(ni,nj,grid)){
                dfs(ni,nj,grid);
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