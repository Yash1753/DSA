class Solution {
public:
    int n;
    vector<vector<int>>dp;
    static bool lambda(string &s1, string &s2){
        return s1.length() < s2.length();
    }
        bool isPred(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();
        
        if(M >= N || N-M != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==M;
    }
    

    int LIS(vector<string>& words, int curr , int prev){
        if(curr == n) return 0;

        if(prev !=-1 && dp[curr][prev] != -1) return dp[curr][prev];
        int taken = 0;
        if(prev == -1 || isPred(words[prev], words[curr]))
            taken = 1 + LIS(words, curr+1, curr);
        
        int not_taken = LIS(words, curr+1, prev);

        if(prev!=-1){
            dp[curr][prev] = max(taken,not_taken);
        }

        return max(taken,not_taken);
    }


    int longestStrChain(vector<string>& words) {
        //words array h
        //chain chaiye maxx length to make words good such that predecoors ek change and seqyuenmce sAME    
         n = words.size();
         dp.resize(1001,vector<int>(1001,-1));
        sort(words.begin(), words.end(), lambda);
       
        return LIS(words, 0, -1); //words, ind, prev


    }
};