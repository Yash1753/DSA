class Solution {
public:
    int helper(vector<vector<int>>& dp, int i, int j, vector<vector<int>>& obstacleGrid) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        int up = helper(dp, i - 1, j, obstacleGrid);
        int left = helper(dp, i, j - 1, obstacleGrid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(dp, m - 1, n - 1, obstacleGrid);
    }
};
