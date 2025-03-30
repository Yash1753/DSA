class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i =0 ; i < n ; i++){
            int oddExpand = expand(s,i,i);
            int evenExpand = expand(s,i,i+1);
            ans+= oddExpand+ evenExpand;
        }

        return ans;
    }

private : 
    int expand(string s,int i , int j){
        int cnt = 0;
        while(i >=0 && j< s.length() && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
};





