class Solution {
public:
vector<int>Parent;
    vector<int>Rank;
    int find(int i){
        if(i == Parent[i]) return i;
        return Parent[i] = find(Parent[i]);
    }

    void Union(int x, int y){
        int Px = find(x);
        int Py = find(y);

        if(Px != Py){
            if(Rank[Px] == Rank[Py]){
                Parent[Px] = Py;
                Rank[Py]++;
            }else if(Rank[Px] > Rank[Py]){
                Parent[Py] = Px;
            }else{
                Parent[Px] = Py;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        Parent.resize(n);
        Rank.resize(n,0);
        int components = n;

        if(connections.size() < n-1) return -1;

        for(int i = 0 ; i < n ; i++){
            Parent[i] = i;
        }

        for(auto &it : connections){
            int a = it[0];
            int b = it[1];
            Union(a,b);
            
            
        }
        unordered_set<int>s;
        for(auto &v : Parent){
            s.insert(find(v));
        }
        return s.size()-1;
    }
};