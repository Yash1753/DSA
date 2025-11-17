class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int last_index = -1;
        int i = 0;
        while(i < n){
            if(nums[i] == 1){
                if(last_index == -1){
                    last_index = i;
                }else{
                    if(i-last_index-1 < k){
                        return false;
                    }
                    last_index = i;
                }
                
            }
            i++;
        }
        return true;
    }
};