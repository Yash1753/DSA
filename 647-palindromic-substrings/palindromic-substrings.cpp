class Solution {
public:
    int countSubstrings(string s) {
        //bottom up diret approach h
        //ek odd evn approach h
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1));

        for(int i = 0 ; i <= n ;i++){
            dp[i][i] = true;
        }
        int cnt = 0;
        //normal template maar do
        for(int L = 1 ;  L <= n ; L++){
            for(int i = 0 ; i+L-1 < n ; i++){
                int j = i + L -1;

                if(i == j) dp[i][j] =  true;
                else if(i+1 == j) dp[i][j] = s[i] == s[j];
                else{
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
                }

                if(dp[i][j])cnt++;
            }
        }

        return cnt;
    }
};