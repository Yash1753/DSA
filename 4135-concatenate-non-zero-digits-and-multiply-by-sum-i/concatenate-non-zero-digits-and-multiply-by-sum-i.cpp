class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = "";

        string number = to_string(n);
        long long sum = 0;
        for(auto ch : number){
            if(ch != '0'){
                num.push_back(ch);
                sum += (ch - '0');
            }
        }
        if(num.size() == 0) return 0;
        long long ans = stoi(num);
        return ans * sum;
    }
};