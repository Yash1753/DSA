class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u';
    }
    bool isCon(char ch){
        if((ch >= 97 &&  ch <= 122) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u')) return true;

        return false;
    }

    int vowelConsonantScore(string s) {
        int n  = s.length();
        int v = 0 , c = 0;

        for(auto &it : s){
            if(isVowel(it)) v++;
            else if (isCon(it)) c++;
        }

        if(c == 0) return 0;

        return v/c;
        
    }
};