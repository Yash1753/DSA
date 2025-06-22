class Solution {
public:
    string getEncryptedString(string s, int k) {
           int n = s.length();
            k = k%n;
            string ans = "";
        for(int i=0; i<n; i++){
            int ind = (i+k)%n;
            ans.push_back(s[ind]);
        }
        return ans;
    }
};