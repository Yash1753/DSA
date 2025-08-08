class Solution {
public:
    vector<int> topo(unordered_map<int,vector<int>>& adj, vector<int>&indegree,int n){
        vector<int>ans;
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < size(indegree) ; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
                cnt++;
            }
        }

        while(!q.empty()){
            auto u = q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    ans.push_back(v);
                    cnt++;
                }
            }
        }

        if(cnt == n) return ans;
        return {};

        
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int>indegree(numCourses,0);

        for(auto &N :prerequisites ){
            int v = N[0];
            int u = N[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        return topo(adj,indegree,numCourses);
    }
};