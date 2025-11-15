class Solution {
public:
    long long ans;
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        //replace krna h ek within -1e5 and 1e5
        int cntNeg = 0;
        for(auto &ch : nums){
            if(ch < 0) ch = -ch;
        }

        sort(nums.begin(),nums.end());

        return (long long)nums[n-1]*nums[n-2]*1e5;

        

        
    }
};