class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int lcs(string&s1, string&s2, int i, int j){
        if(i >= n || j >=m) return 0;

        //case 1 -> dono same h
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + lcs(s1,s2,i+1,j+1);
        }

        //same nhi h 2 choidce nh ya toh s1 ko lelu and s2 ko aage ya vice versa

        int firstChoice = lcs(s1,s2,i+1,j); 
        int secondChoice = lcs(s1,s2,i,j+1);

        return dp[i][j] = max(firstChoice, secondChoice); 

    }

    int longestCommonSubsequence(string text1, string text2) {
        n = size(text1);
        m = size(text2);
        memset(dp,-1,sizeof(dp));

        return lcs(text1,text2, 0,0);
    }
};