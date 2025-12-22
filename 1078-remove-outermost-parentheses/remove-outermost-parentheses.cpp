class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string ans = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ')'){
                level--;
            }
            if(level != 0){
                ans += s[i];
            }
            if(s[i] == '('){
                level++;
            }
        }

        return ans;
    }
};