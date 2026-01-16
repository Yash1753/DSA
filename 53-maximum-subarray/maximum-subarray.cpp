class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int curr = 0;

        for(auto &it : nums){
            curr = max(curr+it, it);
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};