class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
         //ek apni graph bna lete h
         unordered_map<int,vector<int>> adj;
         unordered_map<int,int>indegree,outdegree;

         for(auto &vec : pairs){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
         }

         //dfs traversal pr pehle startNode-> prop : outdegree-indegree == 1
            int startNode = pairs[0][0];
         for(auto &v : adj){
            int u = v.first;
            if(outdegree[u] - indegree[u] == 1){
                startNode = u;
                break;
            }
         }

         //startNode aagyi ab DFS maar do 
         stack<int>st;
         vector<int>path;

         st.push(startNode);
         while(!st.empty()){
            auto top = st.top();
            if(adj[top].size() != 0){
                st.push(adj[top].back());
                adj[top].pop_back();
            }else{
                path.push_back(st.top());
                st.pop();
            }
         }

        reverse(begin(path),end(path));

        vector<vector<int>>ans;
        for(int i = 0 ; i < path.size()-1 ; i++){
            ans.push_back({path[i],path[i+1]});
        }

        return ans;

    }
};