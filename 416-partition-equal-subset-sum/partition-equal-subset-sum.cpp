class Solution {
public:

    int n;
    //ab krege optimize for that use dp as overlap maar rha
    //2d for sum and idx
    int totalSum;
    
    bool solve(vector<int>&nums, int &sum, int i, int &curr,  vector<vector<int>>&dp){
        if(i == n){
            if(curr == sum) return true;
            else return false;
        }

        if(dp[i][curr] != -1) return dp[i][curr];

        bool take = false;
        bool notTake = false;

        //only take when it is less
        if(curr + nums[i] <= sum){
            curr += nums[i];
            take = solve(nums,sum,i+1,curr,dp);
            curr -= nums[i];
        }

        notTake = solve(nums,sum,i+1,curr,dp);

        return dp[i][curr]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        //subset bnana h where sum in both is true
        //toh naturally whole sum of array should be even
        n = nums.size();

        totalSum = accumulate(nums.begin(),nums.end(),0);

        if(totalSum%2) return false;
        totalSum = totalSum/2;
        int curr = 0;
        //int dp[201][totalSum];
        vector<vector<int>>dp(201,vector<int>(totalSum+1,-1));
        //memset(dp,-1,sizeof(dp));
        return solve(nums,totalSum,0,curr,dp);
        
    }
};