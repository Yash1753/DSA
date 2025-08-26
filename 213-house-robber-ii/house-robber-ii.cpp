class Solution {
public:
    vector<int>dp;

    int helper(vector<int>&nums, int i, int n){

        if(i >n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + helper(nums,i+2,n);
        int nottake =  helper(nums,i+1,n);

        return dp[i] = max(take,nottake);
    }

    int rob(vector<int>& nums) {
        int n = size(nums);
        dp.resize(101,-1);
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);

        int left = helper(nums,0,n-2);

        dp.assign(101,-1);
        int right = helper(nums,1,n-1);

        return max(left,right);
    }
};