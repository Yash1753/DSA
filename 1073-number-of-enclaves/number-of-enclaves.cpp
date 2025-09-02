class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && i < m && j>=0 && j < n && grid[i][j]==1)return true;
        return false;
    }
    void dfs(int i , int j, vector<vector<int>>& grid){
        grid[i][j] = 0;

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(isValid(ni,nj,grid)){
                dfs(ni,nj,grid);
            }
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        //walk to itgher land cell 1>land 0>sea
        //boundary traversal ho jaye ga

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i*j == 0 || i == m-1 || j==n-1){
                    if(grid[i][j] == 1){
                        dfs(i,j,grid);
                    }
                }
            }
        }

        int ans = 0;
         for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               if(grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }
};