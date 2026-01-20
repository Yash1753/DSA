class Solution {
public:
    int countGoodSubstrings(string s) {
     //good string if there are no repeating characters
     //xyzzaz
     unordered_map<char,int>mpp;
     int i = 0;
     int j = 0 ;
     int n = s.length();
    int cnt  =0;
     while(j < n){
        mpp[s[j]]++;
        if(j-i+1 > 3){
            mpp[s[i]]--;
            if(mpp[s[i]] == 0){
                mpp.erase(s[i]);
            }
            i++;
        }

        if(j-i+1 == 3 && mpp.size() == 3 ){
            cnt++;
        }
        j++;
     }   

      

     return cnt;
    }
};