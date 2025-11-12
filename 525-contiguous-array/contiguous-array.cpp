class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        unordered_map<int,int>mpp;
        //mpp[0] = -1;

        int sum = 0;
        int maxLen = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];
            if(sum == 0){
                maxLen = max(maxLen,i+1);
            }
            if(mpp.find(sum) != mpp.end()){
                int currLen = i - mpp[sum] ;
                maxLen = max(currLen,maxLen);
            }else{
                mpp[sum] = i;
            }
           
            
        }
        if(maxLen == INT_MIN) return 0;
        return maxLen;
    }
};