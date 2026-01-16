class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int n = nums.size();
        int cnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
                if(cnt == 0){
                    el = nums[i];
                    cnt = 1;
                }
            }
        }

        int numC = 0;
        for(auto it : nums){
            if(it == el) numC++;
        }

        return numC >= n/2 ? el : -1;
    }
};