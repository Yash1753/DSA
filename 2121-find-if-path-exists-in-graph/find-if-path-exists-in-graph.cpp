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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         //int n = edges.size();
        //int m = edges[0].size();
        if(n == 1) return true;
        Parent.resize(n);
        Rank.resize(n,0);

        for(int i = 0 ; i < n ; i++){
            Parent[i] = i;
        }

        for(auto &edge : edges){
           
         Union(edge[0],edge[1]);
        }

       return find(source) == find(destination);
    }
};