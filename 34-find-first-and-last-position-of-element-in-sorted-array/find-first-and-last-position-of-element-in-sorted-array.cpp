class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ans = lower_bound(nums.begin(),nums.end(),target);
        if(ans == nums.end() || *ans != target) return {-1,-1};
        if(nums.size() == 0) return {-1,-1};
        int first = ans - nums.begin();
        auto last = upper_bound(nums.begin(),nums.end(),target);
        int ret = last - nums.begin();
        //corner cases
        //if last is eaual to nums.end();
        if(last == nums.end()) return {first,ret -1};
        //if there is only one element 
        return {first,ret-1};
    }
};