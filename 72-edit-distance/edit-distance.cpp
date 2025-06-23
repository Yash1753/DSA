class Solution {
public:

    int helper(int i,int j, string s, string t , vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j <0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i] == t[j]) return helper(i-1,j-1,s,t,dp) ;

        return 1 + min( helper(i-1,j-1,s,t,dp), min( helper(i-1,j,s,t,dp),  helper(i,j-1,s,t,dp)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int j =0 ; j <= m ; j++){
            dp[0][j] = j;
        }

        for(int i =0 ; i<= n ; i++){dp[i][0] = i;}

        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j<=m ; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min( dp[i-1][j-1], min( dp[i-1][j],  dp[i][j-1]));
                }
            }
        }



        return dp[n][m];
    }
};