class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int maxScore = INT_MIN;
        int sum = 0;
        unordered_map<int,int>mpp;
        while(j < n){
            sum += nums[j];
            mpp[nums[j]]++;
            while(mpp[nums[j]] > 1){
                sum -= nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            maxScore = max(maxScore,sum);
            j++;
        }
        return maxScore;

    }
};