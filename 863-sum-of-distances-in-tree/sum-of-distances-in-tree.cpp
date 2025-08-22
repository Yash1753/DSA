class Solution {
public:
long result1 = 0;
int N;
vector<int>count;


    int dfsBase(unordered_map<int,vector<int>>&adj, int u, int prev, int currLen){
        int total_count = 1;

        result1 += currLen;
        for(auto&v : adj[u]){
            if(v == prev) continue;
            //total_count++;
            total_count += dfsBase(adj,v,u,currLen+1);
        }
        count[u] = total_count;
        return total_count;

    }

    void dfs(unordered_map<int,vector<int>> &adj, int u, int prev , vector<int>&result){
        for(auto &v : adj[u]){
            if(v == prev) continue;

            result[v] = result[u] - count[v] + (N-count[v]);

            dfs(adj,v,u,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count.resize(n,0);
        N=n;
        vector<int>result(n);

        dfsBase(adj,0,-1,0);
        result[0] = result1;

        dfs(adj,0,-1,result);

        return result;


    }
};