class Solution {
public:
    typedef pair<int,int>P;
    int cnt;

    void dfs(int u , int prev ,unordered_map<int,vector<P>>& adj ){
        for(auto &vec : adj[u] ){
            if(vec.first == prev ) continue;

            if(vec.second == 1) cnt++;

            dfs(vec.first,u,adj);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<P>> adj;
        cnt = 0;
        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        // bht log 0 p aatye and har city ko 0 p lana h return minimum edges changed
        dfs(0,-1,adj);
        return cnt;
    }
};