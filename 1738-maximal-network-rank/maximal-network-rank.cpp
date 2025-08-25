class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        vector<vector<bool>>connected(n,vector<bool>(n,false));
        int maxrank = 0;
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }

        for(int i = 0 ; i < n ;i++){
            for(int j = i+1 ; j < n ;j++){
                int i_rank = degree[i];
                int j_rank = degree[j];

                int rank = i_rank + j_rank;

                if(connected[i][j]) rank--;

                maxrank =max(maxrank,rank); 
            }
        }

        return maxrank;
    }
};