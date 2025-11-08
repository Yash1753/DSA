class Solution {
public:
    typedef pair<int,int>p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        //min cost maangi h mst bnao pr uske liye pehle graph bnao
        unordered_map<int,vector<p>>adj;
        for(int i = 0 ; i < n  ;i++){
            for(int j = i+1 ; j < n ; j++){
                int x1 = points[i][0];int y1 = points[i][1];
                int x2 = points[j][0];int y2 = points[j][1];

                int dist = abs(x2-x1) + abs(y2-y1);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        //graph done
        //ow we can gop wioth prim

        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,0});
        int sum = 0;
        vector<bool>inMST(n,false);
        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            int wt = top.first;
            int node = top.second;

            if(inMST[node]) continue;
            inMST[node] = true;
            sum+=wt;

            for(auto &v : adj[node]){
                 int nn = v.first;
                 int nnW = v.second;
                 if(!inMST[nn]){
                    pq.push({nnW,nn});
                 }
            }
        }

        return sum;
    }
};