class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //directed graph 0  se n-1, 
        //adj ki form m hi fraph h mere pass 

        unordered_map<int,vector<int>>adj;
        int n = graph.size();
        vector<int>indegree(n,0);
        for(int u = 0 ; u < n  ; u++){
            for(auto &v : graph[u]){
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        //reverse krliya for eas traversal 
        //ab kahn for toptologival sort k liye
        queue<int>q;
        for(int i =0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool>isSafe(n,false);
        
        while(!q.empty()){
            auto u = q.front();q.pop();
            isSafe[u] = true;
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            if(isSafe[i]){
                result.push_back(i);
            }
        }

        return result;
    }
};