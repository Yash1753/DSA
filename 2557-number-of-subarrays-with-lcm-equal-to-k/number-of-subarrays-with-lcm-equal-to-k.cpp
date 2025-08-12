class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long curr = nums[i];
            for (int j = i; j < n; ++j) {
                curr = std::lcm((long long)curr, (long long)nums[j]);
                if (curr == k) ++res;
                else if (curr > k || k % curr != 0) break;
            }
        }
        return res;
    }
};