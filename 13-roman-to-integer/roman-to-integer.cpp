class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int j = n-2;
        int ans = mpp[s[n-1]];

        while(j >=0 ){
            if(mpp[s[j]] < mpp[s[j+1]]) ans  -=  mpp[s[j]];
            else{
                ans += mpp[s[j]];
            }
            j--;
        }

        return ans;


        
    }
};