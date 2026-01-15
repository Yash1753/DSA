class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastseen = nums[0];
        int i = 1;
        int j = 1;
        int n = nums.size();
        while(j < n){
            if(nums[j] == lastseen){
                j++;
            }else{
                lastseen = nums[j];
                swap(nums[i],nums[j]);
                
                i++;
                j++;
            }
        }
        return i;
    }

};