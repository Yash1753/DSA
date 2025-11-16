class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length();
        int l = 0;

        int r = 0;
        int cntA = 0;
        int cntB = 0;
        while(r < n){
            if(s[r] == 'a') cntA++;
            else cntB++;
            
            r++;

        }

        return abs(cntA-cntB);
    }
};