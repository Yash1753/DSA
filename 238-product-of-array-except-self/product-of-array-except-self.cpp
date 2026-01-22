class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int totalProductWithoutZero = 1;
        int cntZero = 0;
        for(auto &it : nums){
            totalProduct *=it;
            if(it != 0) totalProductWithoutZero *= it;
            if(it == 0) cntZero++;
        }
        int n = nums.size();
        vector<int>ans(n,0);

        for(int i = 0 ; i < n ; i++){
            if(cntZero > 1) break;
            else if(cntZero == 1) {
                if(nums[i] == 0){
                    ans[i] = totalProductWithoutZero;
                    break;
                }
            }else{
                ans[i] = totalProduct/nums[i];
            }
        }

        return ans;
    }
};