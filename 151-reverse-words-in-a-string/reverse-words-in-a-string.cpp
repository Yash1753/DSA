class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0 ,l = 0 , r = 0;
        reverse(s.begin(),s.end());
        while(i < n){
            while(i < n && s[i] != ' '){
                s[r] = s[i];
                r++;
                i++;
            }

            if(l < r){
                reverse(s.begin() + l , s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++; // avoid empty
        }
        return s.substr(0,r-1);
    }
};