class Solution {
public:

    bool isVowel(char ch){
        if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ) return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxi = 0;
        int cnt = 0;
        //get the first window
        int  i = 0 , j = 0;
       while( j < n ){
            char ch = s[j];

            if(j-i+1 > k){
                char w  = s[i];
                if(isVowel(w)) cnt--;
                i++;
            }

            if(isVowel(ch)) cnt++;

            maxi = max(maxi,cnt);
            j++;
        }
        return maxi;
    }
};