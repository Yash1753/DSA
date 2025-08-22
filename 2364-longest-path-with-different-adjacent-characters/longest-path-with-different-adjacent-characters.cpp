class Solution {
public:
    int result;

     int dfs(unordered_map<int,vector<int>>&adj, int u , int prev,string &s){
        int largest = 0;
        int secondlargest = 0;

        for(int &v : adj[u]){
            if(v == prev) continue;
            int temp = dfs(adj,v,u,s);
            if(s[u] == s[v]) continue;

            if(secondlargest < temp){
                secondlargest = temp;
            }
            if(largest < secondlargest){
                swap(largest,secondlargest);
            }

        }

        int yahi = 1 + largest + secondlargest;
        int upper = 1 + max(largest, secondlargest);
        int root = 1;

        result = max({result,yahi,upper,root});
        return max(root, upper);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();  
        result = 0;
        unordered_map<int,vector<int>>adj;
        for(int i = 1 ; i <n ; i++){
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj,0,-1,s);
        return result;
    }
};