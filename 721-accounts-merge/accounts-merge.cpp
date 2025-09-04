class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px!=py){
            if(rank[px] > rank[py]) parent[py] = px;
            else if(rank[px] < rank[py]) parent[px] = py;
            else {
                parent[px] = py;
                rank[py]++;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //list of accounts
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
        //common email h merge // return name emails sorted
        //dsu lega g toph likh lete h

        unordered_map<string,int>mpp; //storing mail to node

        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                if(mpp.find(accounts[i][j]) == mpp.end()){
                    mpp[accounts[i][j]] = i;
                }else{
                    Union(mpp[accounts[i][j]] , i);
                }
            }
        }

        //yaha meris trig with odes store hogyi ab soprt wla game 
       vector<vector<string>> merged(n);
        for(auto &it : mpp){
            string mail = it.first;
            int node = find(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0 ; i < n ; i++){
            if(merged[i].size() == 0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(merged[i].begin(),merged[i].end());
            for(int j = 0 ; j < merged[i].size() ; j++ ){
                temp.push_back(merged[i][j]);
            }
            ans.push_back(temp);

        }
        return ans;


    }//name -> number of emails

};