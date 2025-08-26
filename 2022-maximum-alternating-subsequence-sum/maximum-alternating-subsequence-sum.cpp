class Solution {
public:
    vector<vector<long long>>dp;

    long long solve(int idx , vector<int>&nums, int flag){
        //mere pass index vgera h base condiotions lihte
        if(idx >= nums.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];
        long long skip = solve(idx+1,nums,flag);
        long long val = nums[idx];
        //check flag
        if(!flag) val *= -1;

        long long take = val + solve(idx+1,nums,!flag);

        return  dp[idx][flag] = max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        //take not take bn jayega
        dp.resize(1e5+1, vector<long long>(2,-1));
        int n = nums.size();
        int flag = 1;

           return  solve(0,nums,flag);

        


    }
};