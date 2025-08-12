class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto &vec : times ){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v,w});
        }

        vector<int> res(n+1, INT_MAX);
        res[0] = INT_MIN;
        for(int i = 1 ; i <=n ; i++) res[i] = INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;

        res[k] = 0;

        pq.push({0,k});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int w = top.first;
            int u = top.second;

            for(auto &vec : adj[u]){
                int wt = vec.second;
                int adjNode = vec.first;

                if(wt+w < res[adjNode]){
                    res[adjNode] = wt+w;
                    pq.push({wt+w , adjNode});
                }
            }

          
        }
       int ans = *max_element(res.begin(), res.end());
       if(ans == INT_MAX) return -1;
       
       return ans;

    }
};