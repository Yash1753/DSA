class Solution {
public:
int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};

    bool isvalid(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && i < m && j <n && j>=0 && grid[i][j] == 0) return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j]= 1;

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(isvalid(ni,nj,grid)){
                dfs(ni,nj,grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        //pehle ye socho ki boundary wlae toh hio hi nhi skte
        //jo boundary se ho connect vvo bhi nhi ho sktya

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i*j == 0 || i == m-1 || j ==n-1){
                    if(grid[i][j] == 0){
                        dfs(i,j,grid);
                    }
                }
            }
        }

        //vaha se saaqre boundary cionnected 1 hojayge zero
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                       cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};