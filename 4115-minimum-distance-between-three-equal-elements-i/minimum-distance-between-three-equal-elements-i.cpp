class Solution {
public:
    int solve(vector<int>num){
        int n = num.size();
        //sort(num.begin(),num.end());

        int temp = INT_MAX;
        for(int i = 2 ; i < n ; i++){
            int a = 2*(num[i] - num[i-2]);
            temp = min(temp,a);
        }
        return temp;
    }

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;

        unordered_map<int,vector<int>>mp;

       for(int i = 0 ; i < n ; i++){
            mp[nums[i]].push_back(i);
       }

        int maxi = INT_MAX;
       for(auto &it : mp){
        if(it.second.size() >= 3){
            int dis = solve(it.second);
            maxi = min(maxi,dis);
        }
       }
       return maxi == INT_MAX?-1:maxi;
    }
};