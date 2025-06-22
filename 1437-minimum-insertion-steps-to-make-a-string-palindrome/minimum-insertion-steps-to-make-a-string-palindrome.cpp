class Solution {
public:

    int LCS(int i, int j, string& s, string& r ,vector<vector<int>>& dp ){
        if( i <0 || j < 0 ) return 0;

        if(dp[i][j]!= -1) return dp[i][j];

        if(s[i] == r[j]){
            dp[i][j] = 1 + LCS(i-1,j-1,s,r,dp); 
        }else{
            dp[i][j] = max(LCS(i-1,j,s,r,dp) , LCS(i,j-1,s,r,dp));
        }

        return dp[i][j];
    }

    int minInsertions(string s) {
        string r = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(r.size(), vector<int>(r.size(), -1));
        return r.length() - LCS(s.size()-1,s.size()-1,s,r,dp);

    }
};