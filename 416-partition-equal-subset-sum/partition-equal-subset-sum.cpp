class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool helper(int i,int sum, int target , vector<int>&nums){
        if(i >=n ) return false;
        if(sum == target) return true;
        if(dp[i][sum] != -1) return dp[i][sum];
        //taek not take
        
        bool take =  nums[i] + sum <= target ?  helper(i+1,sum+ nums[i], target,nums) : false;
        bool nottake =  helper(i+1,sum, target,nums);
        return dp[i][sum]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum%2) return false;
        dp.resize(n,vector<int>(sum/2+1,-1));
        
        return helper(0,0,sum/2, nums);
    }
};