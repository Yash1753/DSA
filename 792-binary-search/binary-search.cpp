class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto L = lower_bound(nums.begin(), nums.end(),target) - nums.begin();

        return L == nums.size() || nums[L] != target ? -1 : L;
    }
};