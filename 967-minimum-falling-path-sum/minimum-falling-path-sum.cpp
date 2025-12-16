class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i = 0 ; i < n ; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int down =  dp[i-1][j];
                int left = INT_MAX;
                int right = INT_MAX;
                if(j> 0) left =  dp[i-1][j-1]; 
                if(j < n-1) right = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] +min({down,left,right}); 
            }
        }

        int ans = *min_element(dp[m-1].begin(), dp[m-1].end());

        return ans;
    }
};