class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //longest substr without repeating characters
        unordered_map<char,int>mpp;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxi = 0;

        while( j < n){
            mpp[s[j]]++;

            while(mpp[s[j]] > 1){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};