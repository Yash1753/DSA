class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int j = -1;
        int i = 0;
        int ans = 0;
        int cnt =0;
        while(i < n){
            if(nums[i] == 0){
                i++;
                cnt++;
            }else{
                i++;
            }

            if(cnt > k){
                j++;
                if(nums[j] == 0) cnt--;
            }

            ans = max(ans,i-j-1);
        }
        return ans;
    }
};