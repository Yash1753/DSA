class Solution {
public:
int n;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     n = nums.size();
        sort(nums.begin(),nums.end());
     vector<int>dp(n,1);
     vector<int>prev(n,-1);

     int lastind = 0;
     int maxL = 0;

     for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(nums[i] % nums[j] == 0){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }

                if(dp[i] > maxL){
                    maxL = dp[i];
                    lastind = i;
                }
            }
        }
     }  
     vector<int>temp;
     while(lastind != -1){
        temp.push_back(nums[lastind]);
        lastind = prev[lastind];
     }

     return temp;

    }
};