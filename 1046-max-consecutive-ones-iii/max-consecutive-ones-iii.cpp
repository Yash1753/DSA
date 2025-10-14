class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int j = -1 ; //release
        int i = 0; //acquire

        int cnt = 0;
        int sizeA = 0;

        while(i < n){
            if(nums[i] == 0){
                cnt++;
                i++;
            }else i++;

            //check valid

            while(cnt > k){
                j++;
                if(nums[j] == 0) cnt--;
            }

            //check maxi
            sizeA = max(sizeA, i-j-1);
        }


        return sizeA;
    }
};