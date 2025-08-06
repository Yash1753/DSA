class Solution {
public:

    void DFS(unordered_map<int,vector<int>> &adj, int u , vector<bool>&visited){
        if(visited[u] == true) return;

        visited[u] = true;

        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool>isVisited(V,false);
        unordered_map<int,vector<int>> adj;

        for(int i = 0 ; i <V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }


        }
        int cnt = 0;
        for(int i = 0 ; i < V ; i++){
            if(!isVisited[i]){
                DFS(adj,i,isVisited);
                cnt++;
            }
        }
        return cnt;
    }
};