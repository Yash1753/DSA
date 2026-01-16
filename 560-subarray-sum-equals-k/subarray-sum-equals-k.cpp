class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        /* for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = i ; j < n ; j++){
                sum += nums[j];
                if(sum == k) cnt++;
            }
        } */
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0;

        for(int &num : nums){
            sum += num;

            if(mp.count(sum-k)){
                cnt += mp[sum-k];
            }

            mp[sum]++;
        }

        return cnt;

       
    }
};