class Solution {
public:
    int m,n;
    //int dp[201][201][1005];

    int solve(int x, int y, int k,vector<vector<int>>& grid,  vector<vector<vector<int>>>&dp){
        
        if(k < 0) return -1e9;
        if(x >= m || y >=n) return -1e9;

        if(x == m-1 && y == n-1){
            if(min(1,grid[x][y]) <= k){
                return grid[x][y];
            }else{
                return -1e9;
            }
        }

        if(dp[x][y][k] != -1) return dp[x][y][k];

        int right = grid[x][y] + solve(x,y+1,k-min(1,grid[x][y]),grid,dp);
        int down = grid[x][y] + solve(x+1,y,k-min(1,grid[x][y]),grid,dp);

        return dp[x][y][k] =  max(right,down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        //right and down possible
        //total cost k se niche rehni chaiye
        //sirf 2 direction h dp and check time constrain
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        int ans = solve(0,0,k,grid,dp);
        if(ans  < 0) return -1;
        return ans;
    }
};