class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1}, {0,1},{1,0}};
    typedef pair<int,int>P;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //multisource bfs socho
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n,vector<int>(m,-1));
        queue<P>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();
                q.pop();

                int i = top.first;
                int j = top.second;

                for(auto &dir: directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >=0 && new_i < n && new_j >=0 && new_j <m && result[new_i][new_j] == -1){
                        q.push({new_i, new_j});
                        result[new_i][new_j] = result[i][j] +1;
                    }
                }
            }
        }

        return result;
    }
};