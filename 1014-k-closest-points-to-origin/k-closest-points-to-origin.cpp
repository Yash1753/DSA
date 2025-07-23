class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P>pq;
        vector<vector<int>>ans;

        for(auto it:points){
            pq.push({it[0] * it[0] + it[1]*it[1],{it[0],it[1]}});
            if(pq.size() > k){
                pq.pop();
            }

        }

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            ans.push_back({front.second.first,front.second.second});
        }

        return ans;

    }
};