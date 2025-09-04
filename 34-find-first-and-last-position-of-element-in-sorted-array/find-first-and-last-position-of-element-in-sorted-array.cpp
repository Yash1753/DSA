class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
        if( lb == nums.size() || nums[lb] != target) return {-1,-1};
        auto ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

        vector<int>ans;
        ans.push_back(lb);
        ans.push_back(ub-1);
        return ans;
    }
};