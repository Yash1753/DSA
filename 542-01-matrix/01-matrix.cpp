class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //distance and nearest
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ;j < n ; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();q.pop();
                int x = top.first;
                int y = top.second;

                for(auto &dir:directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(nx>=0 && nx < m && ny>=0 && ny < n && res[nx][ny] == -1){
                        res[nx][ny] = 1 + res[x][y];
                        q.push({nx,ny});
                    }
                }
            }
        }

        return res;
    }
};