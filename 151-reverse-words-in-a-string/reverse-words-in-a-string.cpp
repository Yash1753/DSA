class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string res = "";

        while(ss >> token){
            res = token + " " + res;
        }

        res.pop_back();
        return res;
    }
};