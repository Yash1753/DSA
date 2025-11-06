class Solution {
public:

void dfs(unordered_map<int,vector<int>>&adj, unordered_map<int,set<int>>&mp,vector<bool>&visited,int node,int id, vector<int>&nodeId){
        visited[node] = true;
        mp[id].insert(node);
        nodeId[node] = id;
        for(auto&v : adj[node]){
            if(!visited[v]){
                dfs(adj,mp,visited,v,id,nodeId);
            }
        }
    }


    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        //dsu se aasani se hojayega abhi easy preprocess krte
        //pehle bnao graph

        unordered_map<int,vector<int>>adj;
        for(auto &node : connections){
            int u = node[0];
            int v = node[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //ab dfs se component bna lege jaha component ko ek id se dikhaye g

        unordered_map<int,set<int>>mp;

        //ab dfs lgega har node p
        vector<bool>visited(c+1,false);
        vector<int>nodeId(c+1);
        for(int i =0 ;i <=c ; i++){
            if(!visited[i]){
                int id = i;
                dfs(adj,mp,visited, i,id,nodeId);
            }
        }

        vector<int>ans;

        for(auto &q : queries){
            int type = q[0];
            int n = q[1];

            if(type == 1){
                int ID = nodeId[n];
                if(mp[ID].count(n)){
                    ans.push_back(n);
                }else if(!mp[ID].empty()){
                    ans.push_back(*mp[ID].begin());
                }else{
                    ans.push_back(-1);
                }
            }else{
                int ID = nodeId[n];
                mp[ID].erase(n);
            }
        }


        return ans;
    }
};