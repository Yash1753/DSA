class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>ans(n,-1);
        if( n == 0 || n < 2*k+1) return ans;
       

        //last iterations


        //lemme get that window

        long long sum = 0;
        //window size will be 2*k+1
    int windowSize = 2*k+1;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }

        ans[k] = sum / windowSize;


        for(int i = windowSize ; i  < n  ;i++){
            sum += nums[i];
            sum -= nums[i-windowSize];
            ans[i-k] = sum/windowSize;
        }

       
        return ans;
    }
};