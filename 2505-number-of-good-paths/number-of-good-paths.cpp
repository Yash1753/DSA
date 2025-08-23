class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int Px = find(x);
        int Py = find(y);

        if(Px!=Py){
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //dsu se bnega sperate krke goo nodes find kro
        int n = vals.size();
        long result = n;
        
        unordered_map<int,vector<int>>adj;

        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        parent.resize(n);
        rank.resize(n,1);
        vector<int>isActive(n,false);

        for(int i = 0 ; i < n ; i++) parent[i] = i;

        map<int,vector<int>> valNode;

        for(int i = 0 ; i  < n ; i++){
            int value = vals[i];
            valNode[value].push_back(i);
        }

        for(auto &it : valNode ){
            auto nodes = it.second;

            for(auto &u : nodes){
                   for (int &v: adj[u]) {
                    if (isActive[v]) {
                        Union(u, v);
                    }
                }
                isActive[u] = true;
            }


           
            vector<int> tumhare_parents;
            
            for (int &u : nodes) 
                tumhare_parents.push_back(find(u));

            sort(tumhare_parents.begin(), tumhare_parents.end());
                        
            int sz = tumhare_parents.size();
            
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                
                int cur_parent = tumhare_parents[j];
                
                while (j < sz && tumhare_parents[j] == cur_parent) {
                    j++, 
                    count++;
                }
                j--;
                
                result += (count * (count - 1))/2;
            }
        }
        
        return result;

    }
};