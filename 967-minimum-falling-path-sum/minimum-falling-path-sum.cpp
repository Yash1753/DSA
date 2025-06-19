class Solution {
public:

   /*  int helper(int i , int j , vector<vector<int>> &dp , vector<vector<int>> & matrix ){
        if(j < 0 || j>= matrix[0].size()) return 1e9;
        if(i == 0 ) return matrix[0][j];


        if(dp[i][j] != -1) return dp[i][j];
        int up = matrix[i][j] + helper(i-1 , j , dp , matrix);
        int left = matrix[i][j] + helper(i-1 , j-1 , dp , matrix);
        int right = matrix[i][j] + helper(i-1, j+1 , dp , matrix);

        return dp[i][j] = min(up,min(left,right));
    }     YAHA TLE TOH TABULATION LGAO*/

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp (matrix.size() , vector<int>(matrix[0].size(), 0));
        int mini = INT_MAX;
        
        int n = matrix.size();
        int m = matrix[0].size();

        for(int j =0 ; j< m ; j++){
            dp[0][j]= matrix[0][j];
        }

        for(int i = 1 ; i<n; i++){
            for(int j = 0 ; j < m ; j++){
                int l = INT_MAX;
                int r = INT_MAX;
                int s = matrix[i][j] + dp[i-1][j];
                if(j-1 >=0)  l = matrix[i][j] + dp[i-1][j-1];
                if(j+1 < m)  r = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(s, min(l,r));
            }
        }
       
        for(int j = 0 ; j <m ; j++){
            mini = min(mini, dp[n-1][j]);

        }
        return mini;
    }
};