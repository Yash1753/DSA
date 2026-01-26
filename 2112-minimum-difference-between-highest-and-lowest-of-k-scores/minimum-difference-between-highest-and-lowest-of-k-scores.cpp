class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;

        int i = 0;
        int j = k-1;
        sort(nums.begin(),nums.end());
        while(j < n){
            mini = min(mini, nums[j] - nums[i]);
            j++;
            i++;
        }

        return mini;
    }
};