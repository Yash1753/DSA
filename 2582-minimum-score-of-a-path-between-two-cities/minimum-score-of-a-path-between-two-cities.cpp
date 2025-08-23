class Solution {
public:
int result;
    void dfs(int u ,unordered_map<int,vector<pair<int,int>>>&adj,  vector<bool>&visited){
        visited[u] = true;

        for(auto &vec : adj[u] ){
            int v = vec.first;
            int w = vec.second;
            result = min(result, w);
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        } 
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec :  roads){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<bool>visited(n+1, false);
        result = INT_MAX;
        dfs(1,adj,visited);
        return result;
    }
};