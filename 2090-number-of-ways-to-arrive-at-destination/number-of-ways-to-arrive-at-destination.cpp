class Solution {
public:
    int mod = 1e9 + 7;
    using P = pair<long long,int>;

    void dfs( unordered_map<int,vector<P>>&adj, int u , int &cnt, vector<bool>&visited,int sum,int d ){
        visited[u] = true;
        if(sum ==d ) cnt++;

        for(auto &vec : adj[u] ){
            int v = vec.first;
            int w = vec.second;
            if(!visited[v]){
                dfs(adj,v,cnt,visited,sum+w,d);
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        //0 se n-1 -> bidriectional -> graph hogya
        //single edge betwenn 2 node
        // u > v >wt
        //ways btane h 0  se n-1 k minimum m 
        //weighted and minimum dijkstra m aaja
        unordered_map<int,vector<P>>adj; // u,v,w
        for(auto & road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<P,vector<P>,greater<P>>pq; // w,v

        vector<long long>dist(n,LONG_MAX);
        dist[0] = 0;
        pq.push({0.0,0});

        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int u = top.second;
            long long w = top.first;

            for(auto &vec : adj[u] ){
                int v = vec.first;
                int wt = vec.second;

                if((long long)wt+w < dist[v]){
                    dist[v] = wt+w;
                    pq.push({wt+w, v});
                }
            }
        }
       int cnt = 0;
       int d = dist[n-1];
       if (dist[n-1] >= LLONG_MAX/8) return 0; 
       vector<bool>visited(n,false);
      vector<int> order(n); iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(),
             [&](int a, int b){ return dist[a] < dist[b]; });

        vector<int> ways(n, 0);
        ways[0] = 1;
        for (int u : order) {
            if (dist[u] >= LLONG_MAX/8) break; // no more reachable nodes
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w == dist[v]) {           // shortest-path edge
                    ways[v] += ways[u];
                    if (ways[v] >= mod) ways[v] -= mod; // mod
                }
            }
        }
        return ways[n-1];

    }
};