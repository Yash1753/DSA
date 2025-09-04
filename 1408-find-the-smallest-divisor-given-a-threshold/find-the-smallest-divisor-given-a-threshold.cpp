class Solution {
public:
    bool isValid(vector<int>&nums, int k, int m){
        int sum = 0;
        for(auto &num : nums){
            sum += ceil((double)num/(double)m);
          
        }
        if(sum <= k) return true;
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int num = 1;
        while(l<=r){
            int m = (l+r)/2;

            if(isValid(nums,threshold,m)){
                num = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return num;
    }
};