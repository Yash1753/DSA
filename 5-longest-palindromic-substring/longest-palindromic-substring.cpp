class Solution {
public:
    int startIndex;
    int t[1001][1001];
    bool solve(string&s, int i , int j){
        if(i >= j) return true;
        if(t[i][j]!= -1) return t[i][j];
        if(s[i] == s[j]){
            return t[i][j] = solve(s,i+1,j-1);
        }
        
        return false;
    }

    string longestPalindrome(string s) {
        //longest palindrome substr
        int n = s.size();
        startIndex = 0;
        memset(t,-1,sizeof(t));
        int maxL = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j  < n ; j++){
                if(solve(s,i,j)){
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        startIndex = i;
                    }
                }   
            }
        }

        return s.substr(startIndex,maxL);
    }
};