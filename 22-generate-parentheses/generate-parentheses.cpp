class Solution {
public:

    void solve(int n, vector<string>&  ans, int o , int c, string s){
        if(o == c && o+c == n*2){
            ans.push_back(s);
            return;
        }

        if(o <n){
            solve(n,ans,o+1,c,s+"(");
        }

        if(c < o){
            solve(n,ans,o,c+1,s+")");
        }
        


    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,ans,0,0, "");
        return ans;
    }
};