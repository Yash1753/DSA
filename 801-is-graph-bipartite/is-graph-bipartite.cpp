class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;
        int n = graph.size();
        vector<int>color(n,-1);

        for(int v  = 0 ; v < n ; v++){
            adj[v] = graph[v];
        }

        for(int i = 0 ; i <n ; i++){
            if(color[i] == -1){
                if(!DFS(adj,i,color,1)) return false;
            }
            
        }

        return true;
    }

private:
    bool DFS( unordered_map<int,vector<int>> &adj,int u,  vector<int>&color, int CC ){
         if (color[u] != -1)                        // already colored? must match
            return color[u] == CC;
        color[u] = CC;
        

        for(int &v : adj[u]){
            if(color[v] == color[u]) return false;

            if(color[v] == -1){
                if(!DFS(adj,v,color,1-CC)) return false;
            }
        }

        return true;
    }
};