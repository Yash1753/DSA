class Solution {
public:
    int minAnagramLength(string s) {
        //unique elements utha lo
      int n = s.length();
      for(int i = 1 ; i <= n ; i++){
        if(n%i == 0 && isValid(s,i)) return i;
      }
      return n;


    }
private : 
    bool isValid(string &s , int len){
        int freq[26] = {0}; // sb kitne kitne h

        for(int i = 0 ; i < len ; i++) freq[s[i] - 'a']++;

        for(int i = len ; i < s.length() ; i+=len){
            int range[26] = {0};
            for(int j = i ; j < i+len ; j++){
                range[s[j]-'a']++;
            }
            for(int k = 0 ; k < 26 ; k++){
                if(freq[k] != range[k]) return false;
            }
        }
        return true;
    }
};


