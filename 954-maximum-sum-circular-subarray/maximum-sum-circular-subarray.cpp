class Solution {
public:
    int maxKadane(vector<int>& nums){
        int maxi = nums[0];
        int sum = nums[0];
        for(auto i = 1 ; i < nums.size();i++){
            sum = max(sum+nums[i],nums[i]);
            maxi = max(maxi,sum);
        }

        return maxi;
    }
    int minKadane(vector<int>&nums){
        int mini = nums[0];
        int sum = nums[0];
        for(auto i = 1 ; i < nums.size() ; i++){
            sum = min(sum+nums[i],nums[i]);
            mini = min(mini,sum);
        }

        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        //see either it is maxmimum ya minimum - total sum unme se ek max pdega
        int totalSum = 0;
        for(auto &it : nums){
            totalSum += it;
        }
        int maxSum = maxKadane(nums);
        int minSum = minKadane(nums);
        if(maxSum < 0) return maxSum;

        return max(maxSum, totalSum-minSum);
    }
};