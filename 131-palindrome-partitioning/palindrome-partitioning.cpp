class Solution {
public:

    void solve(string &s , int i , vector<string>&curr, vector<vector<int>>&dp, vector<vector<string>> &result){
        if(i >= s.length()){
            result.push_back(curr);
            return;
        }

        //har possible
        for(int j = i ; j < s.length() ; j++){
            if(dp[i][j]){
                curr.push_back(s.substr(i,j-i+1));
                solve(s,j+1,curr,dp,result);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        //all posiible ek toh direct backtrack abd tohda dp se try krte
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 1;
        }

        for(int L = 2 ; L<= n ; L++){
            for(int i = 0 ; i < n-L + 1 ; i++){
                int j  = L+i-1;
                if(s[i] == s[j]){
                    if(L == 2) dp[i][j]  = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }

            }
        }

        vector<string> curr;
        vector<vector<string>> result;

        solve(s,0,curr,dp,result);
        return result;
    }
};