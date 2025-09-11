class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i, int amount, vector<int>&coins){
        if(i == 0) return amount%coins[i] == 0;
        if(amount == 0) return 1;
        int take = 0;
        
       if(dp[i][amount] != -1) return dp[i][amount];
        if(coins[i] <= amount)
            take = solve(i,amount-coins[i], coins);
            
        int nottake = solve(i-1,amount,coins);
        

        return dp[i][amount]=take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins);
    }
};