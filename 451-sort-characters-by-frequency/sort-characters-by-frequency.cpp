class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;
        for(auto &it : s){
            mpp[it]++;
        }

        for(auto &it : mpp){
            pq.push({it.second,it.first});
        }

        string ans = "";

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int cnt = top.first;
            char ch = top.second;

            while(cnt--){
                ans += ch;
            }

        }

        return ans;
    }
};