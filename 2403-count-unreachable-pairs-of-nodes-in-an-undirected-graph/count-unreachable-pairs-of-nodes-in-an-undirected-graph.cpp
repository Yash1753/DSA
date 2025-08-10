class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int Px = find(x);        
        int Py = find(y);

        if( Px != Py){
            if(rank[Px] == rank[Py]){
                parent[Px] = Py;
                rank[Py]++;
            }else if(rank[Px] > rank[Py]){
                parent[Py] = Px;
            }else{
                parent[Px] = Py;
            }
        }        
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0 ; i < n; i++){
            parent[i] = i;
        }
        
        //make unios
        for(auto &v : edges){
            int a = v[0];
            int b = v[1];

            Union(a,b);
        }

        long long result = 0;
        long long rem = n;
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
            int pp = find(i);
            mp[pp]++;
        }


        for(auto it : mp){
            rem = rem-it.second;
            result += it.second * rem; 
        }

        return result;
    }
};