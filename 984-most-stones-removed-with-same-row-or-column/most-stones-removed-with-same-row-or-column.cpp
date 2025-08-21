class Solution {
public:
    vector<int>Parent;
    vector<int>Rank;

    int find(int x){
        if(x == Parent[x]) return x;

        return Parent[x] = find(Parent[x]);
    }

    void Union(int x, int y){
        int X = find(x);
        int Y = find(y);

        if(X!=Y){
            if(Rank[X] == Rank[Y]){
                Parent[X] = Y;
                Rank[Y]++;
            }else if( Rank[X] > Rank[Y]){
                Parent[Y] = X;
            }else{
                Parent[X] = Y;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        // n stone and remove kr skte if it shares samwe row or coloumn as other not removed yet
        //maximum to remove 
        int n = stones.size();
        int m = stones[0].size();
        Parent.resize(n);
        Rank.resize(n,0);

        unordered_map<int,vector<int>> adj;
       /*  for(auto &edge : stones){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        } */

        for(int i = 0 ; i < n ; i++){
            Parent[i] = i;
        }

       for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                Union(i,j);
            }
        }
       }

       int cnt = 0;
       for(int i = 0 ; i < n ; i++){
        if(i == find(i)) cnt++;
       }

       return n-cnt;


    }
};