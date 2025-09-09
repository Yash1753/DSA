class Solution {
public:
    int m,n;
    int dp[201][201];
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n ) return INT_MAX;

        if(i == m-1 && j == n-1) return grid[i][j]; 
        if(dp[i][j] != -1) return dp[i][j];
        int down = i < m-1 ? grid[i][j] + helper(i+1,j,grid) : INT_MAX;
        int right = j < n-1 ? grid[i][j] + helper(i,j+1,grid) : INT_MAX;

        return dp[i][j]=min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        //non negative numbers it become ez
        //minimize tht sum
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));

        return helper(0,0,grid);
    }
};