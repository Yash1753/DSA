class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int neg = 0;
        for(auto &it : s){
            if(it == '('){
                // if(cnt < 0)cnt--;
                // else cnt++;
                cnt++;
            }
            else{
                if(cnt <=0) neg++;
                else cnt--;

            }
        }
        return abs(cnt) + abs(neg);
    }
};