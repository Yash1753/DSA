class Solution {
public:
    typedef pair<int,int>P;

    int dfs(unordered_map<int,vector<int>>&adj, int u, int prev,vector<bool>& hasApple ){
        int time = 0;
        //3 cases bnte h ---> 1) child has apple toh 2 bhej do add m 2) node has apple same 2 bhej do vrna 3rd 0 bhej do

        for(int &v :adj[u]){
            if(v == prev) continue;

            int time_child = dfs(adj,v,u,hasApple);

            if(hasApple[v] || time_child > 0 ){
                time += time_child+2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge : edges){
            int  u = edge[0];
            int  v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj,0,-1,hasApple);
       
    }
};