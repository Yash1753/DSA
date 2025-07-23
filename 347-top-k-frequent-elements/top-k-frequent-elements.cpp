class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>>pq;

        for(auto it : nums){
            mpp[it]++;
        }

        for(auto it:mpp){
            pq.push(make_pair(it.second,it.first));
        }

        vector<int>ans;

        while(k--){
            auto front = pq.top();
            pq.pop();

            ans.push_back(front.second);
        }

        return ans;




    }
};