class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int oneJump = solve(n-1);
        int twoJump = solve(n-2);

        return dp[n] =  oneJump + twoJump;
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};