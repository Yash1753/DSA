class Solution {
public:
    unordered_map<int,vector<int>>mpp;
    int cnt = 0;


    int dfs(int node, int parent, vector<int>&values, int k){
        long long sum  = values[node];

       for(auto &v : mpp[node]){
        if(v != parent){
            sum += dfs(v,node,values,k);
        }
       }

       if(sum%k == 0){
        cnt++;
        return 0;
       }

       return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        

        for(auto node : edges){
            int u = node[0];
            int v = node[1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        dfs(0,-1,values,k);
        return cnt;
    }
};