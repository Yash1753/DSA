class Solution {
public:

    int LCS(int i , int j ,string &s, string &r, vector<vector<int>>&dp){
        if( i <0 || j <0) return 0;


        if(dp[i][j] != -1) return dp[i][j];  
        //matching case likh
        if(s[i] == r[j]){
            dp[i][j] = 1+ LCS(i-1,j-1, s, r,dp);
        }else{
            dp[i][j] = max(LCS(i-1,j,s,r,dp), LCS(i,j-1,s,r,dp));
        }

        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.length();
        vector<vector<int>> dp (n ,vector<int>(n,-1));
        return LCS(n-1,n-1, s, r, dp);

    }
};