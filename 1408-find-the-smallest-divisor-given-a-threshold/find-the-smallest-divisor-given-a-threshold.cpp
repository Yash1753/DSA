class Solution {
public:
int n;
    bool fn(int mid,vector<int>& nums, int threshold){
        long long sum  =0;

        for(auto it : nums){
            sum += ceil((double)it/(double)mid);
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        n = size(nums);

        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(fn(mid,nums,threshold)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};