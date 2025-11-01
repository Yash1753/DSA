class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // base case
        
        int prefixSum = 0;
        int ans = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // Check if we’ve seen a prefix sum that would make this subarray sum to k
            if (prefixCount.count(prefixSum - k)) {
                ans += prefixCount[prefixSum - k];
            }
            
            prefixCount[prefixSum]++;
        }
        
        return ans;
    }
};
