class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;


        

        int n = s.length();
        int j = n-1;
        int sum = mpp[s[j]];
        j--;
        while(j >= 0){
            if(mpp[s[j]] < mpp[s[j+1]]){
                sum -= mpp[s[j]];
            }else{
                sum += mpp[s[j]];
            }
            j--;
        }

        return sum;
    }
};