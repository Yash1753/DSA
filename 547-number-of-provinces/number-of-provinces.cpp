class Solution {
public:
int n;
vector<int>parent;
vector<int>rank;
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void Union(int x, int y){
    int X =find(x);
    int Y =find(y);

    if(X==Y)return;

    if(rank[X] > rank[Y]){
        parent[Y] =X;
    }else if(rank[X] < rank[Y]){
        parent[X] = Y;
    }else{
        parent[X] = Y;
        rank[Y]++;
    }
}

 /*   

    void DFS(int i,  unordered_map<int,vector<int>>&adj,vector<bool>&vis ){
        //if(i >=n || vis[i]) return;
        vis[i] = true;

        for(auto &v : adj[i]){
            if(!vis[v]){
                DFS(v,adj,vis);
            }
        }
    }
 */
    int findCircleNum(vector<vector<int>>& isConnected) {
        //a->&&b-=>c so a->c
        //nmatrix n size and n are number of cities
        n = isConnected.size();
        //har internal vector k har index p numbe of connection h if 1 h toh connecteed h
        //ab ek list bnate to help further
        //unordered_map<int,vector<int>> adj;
        rank.resize(n,0);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <  n ; j++){
                if(isConnected[i][j] == 1){
                    Union(i,j);
                }
            }
        }

        // 0->1 || 1->0 || 3->{}
        //int cnt = 0;
        /* vector<bool>vis(n,false);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS(i,adj,vis);
                cnt++;
            }

        }
 */
    unordered_set<int>s;
    for(auto &v : parent){
        s.insert(find(v));
    }


        return s.size();


    }
};