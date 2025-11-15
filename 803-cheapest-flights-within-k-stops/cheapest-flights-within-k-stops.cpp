class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans  =INT_MAX;
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &edge : flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
        }
        vector<int>dist(n,INT_MAX);
        //disktra
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;
        int steps = 0;
        while(!q.empty() && steps <= k){
            int N = q.size();
            while(N--){
                auto tp = q.front();q.pop();
                int node = tp.first;
                int wt = tp.second;

                for(auto &ngr : adj[node]){
                    int v = ngr.first;
                    int w = ngr.second;

                    if(dist[v] > w + wt){
                        dist[v] = w+wt;
                        q.push({v,dist[v]});
                    }


                }
            }
            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};