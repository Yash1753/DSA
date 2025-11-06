class Solution {
public:
    int n;

    void DFS(int i,  unordered_map<int,vector<int>>&adj,vector<bool>&vis ){
        //if(i >=n || vis[i]) return;
        vis[i] = true;

        for(auto &v : adj[i]){
            if(!vis[v]){
                DFS(v,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //a->&&b-=>c so a->c
        //nmatrix n size and n are number of cities
        n = isConnected.size();
        //har internal vector k har index p numbe of connection h if 1 h toh connecteed h
        //ab ek list bnate to help further
        unordered_map<int,vector<int>> adj;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <  n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // 0->1 || 1->0 || 3->{}
        int cnt = 0;
        vector<bool>vis(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS(i,adj,vis);
                cnt++;
            }

        }

        return cnt;


    }
};