class Solution {
public:
    int helper(int i , int j , vector<vector<int>>&dp,vector<vector<int>>& triangle ){
        if(i == triangle.size()-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = triangle[i][j] + helper(i+1,j,dp,triangle);
        int dg = triangle[i][j] + helper(i+1, j+1, dp, triangle);

        return dp[i][j] = min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp (triangle.size(), vector<int> (triangle.size(), -1));
        return helper(0,0,dp,triangle);
    }
};