class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int n = nums.size();
        if(n    <2)return 0;
        int ans = 0;
        for(int i = 2 ; i  < n ; i++){
            if(nums[i]- nums[i-1] == nums[i-1]-nums[i-2]){
                dp[i] = dp[i-1]+1;
                ans += dp[i];
            }
        }

        return ans;
    }
};