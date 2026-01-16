class Solution {
public:
int M;int N;
    int dp[101][101];
    int helper(int i, int j){
        if(i >= M || j >=N) return 0;
        if( i == M-1 && j == N-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int bottom =  helper(i+1,j);
        int right =  helper(i,j+1);

        return dp[i][j] = bottom+right;
    }

    int uniquePaths(int m, int n) {
        M=m;
        N=n;
        memset(dp,-1,sizeof(dp));
        return helper(0,0);
    }
};