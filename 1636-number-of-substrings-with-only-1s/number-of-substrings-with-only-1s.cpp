class Solution {
public:
    long long M = 1e9+7;
    int numSub(string s) {
        long long cnt1 = 0;
        long long ans =0;

        for(auto &ch : s){
            if(ch == '1'){
                cnt1++;
            }else{
                ans = (ans + (cnt1*(cnt1+1))/2) % M;
                cnt1 = 0;
            }
        }
        ans = (ans + cnt1*(cnt1+1)/2) % M;

         return (int)ans;


    }
};