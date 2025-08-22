class Solution {
public:
    vector<int>ans;
    vector<int>count;

    void dfs(unordered_map<int,vector<int>>&adj, int u, int prev , string &labels){
        char my_label = labels[u];

        int before_visiting = count[my_label - 'a'];

        count[my_label-'a']++;

        for(auto&v : adj[u]){
            if(v == prev) continue;

            dfs(adj,v,u,labels);
        }

        ans[u] = count[my_label-'a']- before_visiting;
    }


    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //tree -> undirected 
        // n nodes and n-1 edges
        //har node k pass ek label h
        unordered_map<int,vector<int>> adj;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,0);
        count.resize(26,0);

        dfs(adj,0,-1,labels);

        return ans;

    }
};