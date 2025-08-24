class DSU{
    public:
        vector<int>parent;
        vector<int>rank;
        int components;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            components = n;

            iota(parent.begin(), parent.end(),0);
        }


        int find(int x){
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }

        void Union(int x , int y){
            int px = find(x);
            int py = find(y);

            if(px != py){
                if(rank[px] == rank[py]){
                    parent[px] = py;
                    rank[py]++;
                }else if(rank[px] > rank[py]){
                    parent[py] = px;
                }else{
                    parent[px] = py;
                }

                
            }
            components--;
        }

        bool isSingle(){
            return components == 1;
        }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //DSU legaga kyuki min edge removal type hogya nad phir alice and bob ko alg rkhega 
        //jo bghi max hoga uuse total edges se mionuis krdege
        //pehle type 3 ko banyege

        DSU alice(n);
        DSU bob(n);

        auto lambda = [&](vector<int>&v1 , vector<int>&v2){
            return v1[0] > v2[0];
        };

        sort(edges.begin(), edges.end(), lambda);
        int cnt = 0;
        for(auto &vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];
            bool added = false;
            if(type == 3){
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u,v);
                    added= true;
                }
                 if(bob.find(u) != bob.find(v)){
                    bob.Union(u,v);
                    added = true;
                }

                if(added) cnt++;

            }else if(type == 2){
                if(bob.find(u) != bob.find(v)){
                    bob.Union(u,v);
                   cnt++;
                }
            }else{
                if(alice.find(u) != alice.find(v)){
                    alice.Union(u,v);
                    cnt++;
                }
            }
        }

        if(alice.isSingle() && bob.isSingle()){
            return edges.size()-cnt;
        }

        return -1;
    }
};