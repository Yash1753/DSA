class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int i = 0 , j = 0;
        int n = s.length();
        vector<int>hash(26,0);
        int maxCnt = 0;
        while(j < n){
            hash[s[j]-'A']++;
            maxCnt = max(maxCnt, hash[s[j]-'A']);
            //maxLen = max(maxLen, )
           if((j-i+1) - maxCnt > k){
                hash[s[i]-'A']--;
                i++;
           }

           maxLen = max(maxLen, j-i+1);


            j++;

        }

        return maxLen;
    }
};