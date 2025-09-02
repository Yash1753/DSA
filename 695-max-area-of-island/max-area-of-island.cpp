class Solution {
public:
int m,n;


    bool isValid(int i, int j,vector<vector<int>>& grid){
        if(i >=0 && i < m && j < n && j>=0 && grid[i][j] == 1) return true;
        return false;
    }

    void dfs(int i, int j,vector<vector<int>>& grid, int &area){
        grid[i][j] = 0;
        area++;

        if(isValid(i+1,j,grid)){
            dfs(i+1,j,grid,area);
        }
         if(isValid(i-1,j,grid)){
            dfs(i-1,j,grid,area);
        }
         if(isValid(i,j+1,grid)){
            dfs(i,j+1,grid,area);
        }
         if(isValid(i,j-1,grid)){
            dfs(i,j-1,grid,area);
        }


    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //max area chaiye toh har 1 op lgega dfs

         m = grid.size();
         n = grid[0].size();
        int maxArea = 0;
        for(int i =  0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,grid,area);
                    maxArea = max(area,maxArea);
                }
            }
        }

        return maxArea;
    }
};