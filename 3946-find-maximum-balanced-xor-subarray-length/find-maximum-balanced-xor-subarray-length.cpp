class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int xr = 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        //equal number of iodd and even bhi tioh h
        int n = nums.size();
        //map bnana pdega to get count
        map<pair<int,int>,int>mpp;
        mpp[{0,0}] = -1;

        int odd = 0;
        int even = 0;

        while(j < n){
            xr ^= nums[j];
            if(nums[j]%2) odd++;
            else even++;

            int diff = odd-even;
            pair<int,int>key = {xr,diff};

            if(mpp.count(key)){
                ans = max(ans, j - mpp[key]);
            }else{
                mpp[key] = j;
            }
            j++;
        }
        return ans;




    }
};