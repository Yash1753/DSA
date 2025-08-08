class Solution {
public:

    bool topo(unordered_map<int,vector<int>>&adj,vector<int>&inDegree, int N){
        // using kahn algo // topt -> bfs
        queue<int>q;
        int cnt = 0;
        for(int i = 0 ; i < size(inDegree) ; i++){
            if(inDegree[i] == 0){
                q.push(i);
                cnt++;
            }
        }
         //check nodes got visited oir not
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            
            for(int &v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    cnt++;
                }
            }
        }

        if(cnt == N) return true;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //pehle known grtwph fromat m lete h'
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(numCourses,0);

        //make graph
        for(auto &N : prerequisites){
            int u = N[0];
            int v = N[1];
            // v----->u
            adj[v].push_back(u);
            //indegree bdhao
            inDegree[u]++;
        }

        return topo(adj,inDegree,numCourses);


    }
};