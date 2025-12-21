class Solution {
public:
    int n;

    bool fn(int mid,vector<int>& nums, int k){
        long long sum = 0;

        int cnt = 1;

        for(int i = 0 ; i < n ; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                cnt++;
                sum = nums[i];
            }
        }

        return cnt <=k;
    }

    int splitArray(vector<int>& nums, int k) {
        //largest sum is minimized
        //k subarrays bnane h

        n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        int ans;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(fn(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};