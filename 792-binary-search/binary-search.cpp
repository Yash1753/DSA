class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto ans = lower_bound(nums.begin(),nums.end(),target);
        if(ans == nums.end() || nums[ans-nums.begin()] != target ) return -1;
        return ans-nums.begin();
    }
};