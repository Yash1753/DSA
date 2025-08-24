class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y){
        int Px = find(x);
        int Py = find(y);

        if(Px != Py){
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


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0 ; i < n ; i++) parent[i] = i;


        auto lambda = [&](vector<int> &v1 , vector<int>&v2){
            return v1[2] < v2[2];
        };

        for(int i = 0 ; i < queries.size(); i++){
             queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), lambda);
        sort(queries.begin(), queries.end(), lambda);

        vector<bool>result(queries.size());

        int j = 0;
         for(int i = 0 ; i < queries.size(); i++){
            vector<int>query = queries[i];
            int u = query[0];
            int v = query[1];
            int t = query[2];
            int idx = query[3];

            while(j < edgeList.size() && t > edgeList[j][2]){
                Union(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            if (find(u) == find(v)) result[idx] = true;
            else result[idx] = false;
         }

         return result;

       

    }
};