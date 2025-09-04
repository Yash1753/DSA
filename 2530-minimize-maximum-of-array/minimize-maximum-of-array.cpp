class Solution {
public:

    bool isValid(vector<int>&nums, int k){
        vector<long long>arr(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(arr[i] > k) return false;
            long long buffer = k-arr[i];
            arr[i+1] -= buffer; 
        }

        return arr[nums.size()-1] <=k;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(l <= r){
            int m = (l+r)/2;

            if(isValid(nums,m)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};