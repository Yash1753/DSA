class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin  = 1;
        int currMax = 1;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                maxi = max(maxi, 0);
                currMin = 1;
                currMax = 1;
                continue;
            }
            int temp = currMax;
            currMax = max({ nums[i] * currMax, nums[i]* currMin,nums[i]});
            currMin = min( {nums[i] * temp, nums[i]* currMin,nums[i]});
            maxi = max({currMax,currMin,maxi});
        }
        return  maxi;
    }
};