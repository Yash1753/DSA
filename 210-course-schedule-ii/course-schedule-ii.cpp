class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //labelled h toh graph hogya
        //0>numCourses-1

        //preequiste h ki b  to a directed graph h

        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        vector<int>order;
        int cnt = 0;
       
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
                cnt++;
                order.push_back(i);
            }
        }
        //return order of element to basically do all courses 
        // ek k baad doosra toh topological sort aajayega
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto &v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0) {q.push(v);
                cnt++;
                order.push_back(v);
                }
            }
        }
        if(cnt == numCourses) return order;
        return {};

    }
};