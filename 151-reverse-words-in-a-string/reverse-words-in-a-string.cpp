class Solution {
public:
    string reverseWords(string s) {
        vector<string>word;

        while(!s.empty() && s.back() == ' ') s.pop_back();
        int i = 0 , j = 0 ;
        int n  = s.length();
        while(s[i] == ' '){
            i++;
            j++;
        }

        while(j < n){
            if(s[j] == ' '){
                if(i < j){
                    word.push_back(s.substr(i,j-i));
                }
                j++;
                i = j;
            }else{
                j++;
            }
        }
        if(i < j){
                    word.push_back(s.substr(i,j-i));
                }

        reverse(word.begin(),word.end());
        string ans = "";

        for(auto &it : word){
            ans += it;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};