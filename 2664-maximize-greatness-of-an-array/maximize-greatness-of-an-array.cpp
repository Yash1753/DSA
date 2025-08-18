class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());           // O(n log n)
        int n = nums.size();
        int i = 0, j = 0, ans = 0;                // i -> smaller side, j -> candidate larger
        while (j < n) {
            if (nums[j] > nums[i]) {              // found a strictly larger partner for nums[i]
                ans++;
                i++;                               // move to next smallest needing a partner
            }
            j++;                                   // always advance the larger pointer
        }
        return ans;
    }
};
