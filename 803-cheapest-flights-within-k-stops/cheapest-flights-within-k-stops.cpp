class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //n nodes ->
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec :  flights){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
        }
       
        vector<int>dist(n,INT_MAX);

        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;
        int steps = 0;
        while(!q.empty() && steps <=k){
            int N = q.size();
            while(N--){
                auto top = q.front();q.pop();
                int u = top.first;  //niode
                int w = top.second; // wright

                for(auto &vec : adj[u]){
                    //pair - > neigh,wt
                    int v = vec.first;
                    int wt = vec.second;

                    if(w + wt < dist[v]){
                        dist[v] = w+wt;
                        q.push({v,w+wt});
                    }
                }
            }
            steps++;
        }

        if(dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};