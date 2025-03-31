class Solution {
public:
    void mapping(string&s){
        char mapp[256] = {0};
        char c = 'a';

        for(auto ch : s){
            if(mapp[ch] == 0){
                mapp[ch] = c;
                c++;
            }
        }

       for(int i = 0 ; i < s.length() ; i++){
            s[i] = mapp[s[i]];
       }
    }
    bool isIsomorphic(string s, string t) {
        mapping(s);
        mapping(t);
        if(s==t)return true;

        return false;
    }
};