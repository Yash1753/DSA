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

    bool equationsPossible(vector<string>& equations) {
        int n = size(equations);
        Parent.resize(26);
        Rank.resize(26,0);
        for(int i = 0 ; i< 26 ; i++){
            Parent[i] = i;
            //Rank[i] = 1;
        }

        for(auto &s : equations){
            if(s[1] == '='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(auto &s : equations){
            if(s[1] == '!'){
              char first = s[0];
              char second = s[3];

              int Pa = find(first-'a');
              int Pb = find(second-'a');

              if(Pa == Pb) return false;
            }
        }

        return true;



    }
};