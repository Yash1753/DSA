class Solution {
public:

    int n;
    //fidning diameter basically kehta ki farther from farther is diameter

    pair<int,int> farther(int i,unordered_map<int,vector<int>>&adj ){
        //yaha se distance and farther chaiye let uise bfs

        queue<int>q;
        q.push(i);
        unordered_map<int,bool>vis;
        vis[i] =1;
        int dist =0;
        int farther = i;
        while(!q.empty()){
            //level nikalna h distance k liye
            int size = q.size();
            while(size--){
                int node = q.front();q.pop();
                farther = node;
                for(int &v : adj[node]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }if(!q.empty()) dist++;
        }

        return {farther,dist};
    }

    int findD(unordered_map<int,vector<int>>&adj){
        //find dist from farther n all
        if(adj.size() == 0) return 0;
        auto initial = farther(0,adj);
        auto final = farther(initial.first,adj);

        return final.second; 
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1,adj2;
        int n1 = edges1.size();
        int n2 = edges2.size();
        

        for(auto &edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto &edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int d1 = findD(adj1);
        int d2 = findD(adj2);

        int mereged = (d1+1)/2+(d2+1)/2 +1 ;

        return max({d1,d2,mereged});


    }
};