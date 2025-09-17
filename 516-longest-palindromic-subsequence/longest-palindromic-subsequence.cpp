class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int maxLen = 0;
        int curr = -1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
   for (int i = 0; i < n; ++i) dp[i][i] = 1;

        // L = current substring length
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i + L - 1 < n; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) dp[i][j] = 2;            // two equal chars
                    else dp[i][j] = 2 + dp[i+1][j-1];   // enclosure + inner
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};