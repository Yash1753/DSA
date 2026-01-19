class Solution {
public:

    bool isPossible(vector<int>&nums, int k , int mid){
        int n = nums.size();
        int cnt = 1;
        int sum = 0;

        for(int i =  0 ; i < n ; i++){
            if(sum + nums[i] > mid){
                cnt++;
                sum = nums[i];
            }
            else sum = sum + nums[i];
        }
        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        //subarray h toh sort toh nhi hoga
        int n = size(nums);
        //mimizie the maximum(larget sum) -> go left
        int low =  *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;

        while(low <=high){
            int mid = low + (high-low)/2;

            if(isPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};