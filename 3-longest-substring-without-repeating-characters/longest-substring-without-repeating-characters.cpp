class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       //without duplicates

       vector<int>hash(256,-1);
       int n = s.length();
       int l =0,r=0;
        int ans = 0;

       while(r < n){
         if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]]+1;
            }
         }

         int len = r-l+1;
         ans = max(len,ans);

         hash[s[r]] = r;

         r++;
         //variable window size

       }

       return ans;
    }
};