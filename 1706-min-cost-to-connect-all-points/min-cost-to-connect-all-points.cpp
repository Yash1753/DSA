class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //MST WITH prim but graph chiaye toh grap bnata h
        //pehle adj list bnata h ki from hwere to where 
        vector<vector<pair<int,int>>> adj(points.size()); // node -> weiht
        int V = points.size();
        //created a graph 
        for(int i = 0 ; i< V; i++){
            for( int j = i+1 ; j < V ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        //prim algo minimu spanning tree toh sum maintain krlete h kyuki vhi mujh cost dedega
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0}); // weight, node maintain krte weight pehle for min
        vector<bool>visited(V);
        

        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            int w = top.first;
            int node = top.second;
            if(visited[node]) continue;

            visited[node] = true;

            sum += w;

            for(auto &tmp : adj[node]){
               int vw = tmp.second;
               int v = tmp.first;

                if(!visited[v]){
                    //visited[v] = true;
                    pq.push({vw,v});
                }

            }
        }

        return sum;
    }
};