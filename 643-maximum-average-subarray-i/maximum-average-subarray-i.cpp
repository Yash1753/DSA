class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double sum = 0;
        double maxi = INT_MIN;
        while( j < n){
            sum += nums[j];

            while(j-i+1 > k){
                sum -= nums[i];
                i++;
            }

            if(j-i+1 == k)
                maxi = max(maxi,sum);
            j++;
        }
        double calc = maxi/(double)k;
        return calc;
    }
};