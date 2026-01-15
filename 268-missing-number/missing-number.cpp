class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumThis = accumulate(nums.begin(),nums.end(),0);
        int sumOrig = 0;
        for(int i = 0; i <= n ; i++){
            sumOrig += i;
        } 

        return abs(sumOrig - sumThis);
    }
};