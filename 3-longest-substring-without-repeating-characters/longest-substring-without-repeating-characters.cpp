class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  =s.length();
        int l =0;
        int r = 0;
        unordered_map<char,int>mpp;
        int maxi = 0;
        while(r < n){
            mpp[s[r]]++;
            
            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }

            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};