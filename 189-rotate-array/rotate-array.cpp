class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        vector<int>ans(n);
        while(i < n){
            ans[(i+k)%n] = nums[i];
            i++;
        }
        nums = ans;
        
    }
};