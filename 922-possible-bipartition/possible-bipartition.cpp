class Solution {
public:

    bool bfs(unordered_map<int,vector<int>>&adj, int u , vector<int>&color){
        queue<int>q;
        q.push(u);
        if(color[u] == -1)color[u] = 1;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int &v : adj[top]){
                if(color[v] == color[top]) return false;
                if(color[v] == -1){
                    q.push(v);
                    color[v] = 1-color[top];
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //2 grps 

        unordered_map<int,vector<int>>adj;

        for(auto &vec : dislikes){
            int u = vec[0]; 
            int v = vec[1];

            adj[u].push_back(v); 
            adj[v].push_back(u);

        }

        vector<int> color(n+1 , -1);

        for(int i  =1 ; i <= n ; i++){
            if(!bfs(adj,i,color)) return false;
        }

        return true;
    }
};