class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int>& nums,int i, int p){
        if(i == n){
            return 0 ;
        }
        if(p!= -1 && dp[i][p] != -1) return dp[i][p];
        //taken and notTaken
        int taken = INT_MIN;
        int notTaken = INT_MIN;

        if(p == -1 || nums[i] > nums[p]){
            taken = 1 + solve(nums,i+1,i);
        }
        notTaken = solve(nums,i+1,p);
        if(p != -1)dp[i][p] = max(taken,notTaken);
        return  max(taken,notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        //ek prev main krlege to throw in recurisom
        n = nums.size();
        memset(dp,-1,sizeof(dp));

        return solve(nums,0,-1);
    }
};