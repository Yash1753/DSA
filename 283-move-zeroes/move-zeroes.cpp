class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j  = 0;
        int n = nums.size();
        int i = 0; 
        while(j < n){
            if(nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else{
                j++;
            }
        }
    }
};