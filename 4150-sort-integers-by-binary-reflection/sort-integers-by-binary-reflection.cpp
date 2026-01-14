class Solution {
public:
    string convertToBinary(int n){
        if(n == 0) return "0";

        string s = "";
        while(n){
            int rem = n % 2;
            s += char(rem + '0');
            n = n / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int binaryToDec(string s){
        int ans = 0;
        for(char c : s){
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
            string b = convertToBinary(nums[i]);
            reverse(b.begin(), b.end());     // reflection
            int reflected = binaryToDec(b);
            v.push_back({reflected, nums[i]});
        }

        sort(v.begin(), v.end());

        vector<int> result;
        for(auto &it : v){
            result.push_back(it.second);
        }

        return result;
    }
};
