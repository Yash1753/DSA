class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3] = {-1,-1,-1};

        int cnt = 0;
       for(int i = 0 ; i < s.length() ; i++){
        arr[s[i] - 'a'] = i;
        cnt += 1 + min(arr[0], min(arr[1],arr[2]));

       }

       return cnt;
    }
};