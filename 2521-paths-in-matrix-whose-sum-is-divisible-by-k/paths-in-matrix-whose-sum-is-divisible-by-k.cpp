class Solution {
public:
    int m,n;
    int mod = 1e9 + 7;
    
    int solve(vector<vector<int>>& grid, int k, int i, int j, int sum,vector<vector<vector<int>>>& dp){
        if(i == m || j == n ){
            return 0;
        }
        sum = (sum + grid[i][j]) % k;
        if( i == m-1 && j == n-1){
            //sum += grid[i][j];
            if(sum == 0){
                return 1;
            } 
            else return 0;
        }

        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        long long down = solve(grid,k,i+1,j,sum,dp);

        long long right = solve(grid,k,i,j+1,sum,dp);

        return dp[i][j][sum] = (down + right) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n  = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(grid,k,0,0,0,dp);
    }
};