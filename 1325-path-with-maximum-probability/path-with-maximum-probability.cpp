class Solution {
public:
   

    /* void DFS(unordered_map<int,vector<pair<int,double>>> &adj, double curr, int u, int dest, vector<bool>&visited){
        if(visited[u]) return;

        visited[u] = true;

        if( u == dest){
            prob = max(prob,curr);
        }

        for(auto &vec : adj[u]){
            //yaha pair h int->double // node -> prob

            int v = vec.first;
            double abhiKi = vec.second;

            if(!visited[v]){
                DFS(adj,curr*abhiKi, v, dest,visited);
            }

        }

        visited[u] = false;
    }
 */ // ye nhi chlega tle maarege weighted edges gtoh dijkstra m jao
 //yaha max chaiye toh max_heap m jao
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        //0 se 1 aur uski prob
        priority_queue<P>pq;
        pq.push({1.0,start_node});
        vector<double>result(n,0.0);
        result[start_node] = 1;

        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            double w = top.first;
            int u = top.second;

            for(auto &vec : adj[u]){
                double curr = vec.second;
                int v = vec.first;

                if(w*curr > result[v]){
                    result[v] = w*curr;
                    pq.push({w*curr, v});
                }
            }
        }

        
        return (result[end_node] == INT_MIN) ? 0 : result[end_node];



    }
};