class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Cases
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) {
            for (int ind = 0; ind <= j; ind++) {
                if (p[ind] != '*') return false;
            }
            return true;
        }

        // Memoization
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        }

        if (p[j] == '*') {
            // '*' can match zero characters (j-1) or one character (i-1)
            return dp[i][j] = helper(i - 1, j, s, p, dp) || helper(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};
