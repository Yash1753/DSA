class Solution {
public:
    int m, n;
    const int mod = 1e9 + 7;

    // rem = current sum % k BEFORE adding grid[i][j] (we add it at the start of the function)
    int solve(vector<vector<int>>& grid, int k, int i, int j, int rem, 
              vector<vector<vector<int>>>& dp) {
        if (i == m || j == n) return 0;

        // include current cell's value into remainder
        rem = (rem + grid[i][j]) % k;

        // base case: last cell
        if (i == m - 1 && j == n - 1) {
            return (rem == 0) ? 1 : 0;
        }

        int &cached = dp[i][j][rem];
        if (cached != -1) return cached;

        long long down = solve(grid, k, i + 1, j, rem, dp);
        long long right = solve(grid, k, i, j + 1, rem, dp);

        cached = (down + right) % mod;
        return cached;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // dp[i][j][rem] = number of ways from (i,j) to end when the current remainder
        // before adding grid[i][j] is 'rem'. -1 = uncomputed
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(grid, k, 0, 0, 0, dp);
    }
};
