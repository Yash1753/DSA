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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        //if(word1.compare(word2) == 0) return 0;

        //if(m >= n) swap(n,m);

        vector<vector<int>>dp (n, vector<int>(m,-1));
        cout << LCS(n-1,m-1,word1,word2,dp);
       return (n - LCS(n-1,m-1,word1,word2,dp)) + (m - LCS(n-1,m-1,word1,word2,dp));
    }
};