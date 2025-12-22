class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int j = n-1;
        string ans = "";
        while(j >= 0){
            int number = num[j] - '0';
            if(number%2){
                ans = num.substr(0,j+1);
                break;
            }
            j--;
        }
        return ans;

    }
};