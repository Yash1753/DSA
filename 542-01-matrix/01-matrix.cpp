class Solution {
public:


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //multisources bfs
        vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>res(m,vector<int>(n,-1));
        queue<pair<int,int>>q; //coordinates

        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j  < n ; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i,j});

                }
            }
        }

        while(!q.empty()){
            auto front = q.front();q.pop();
            int x = front.first;
            int y = front.second;

            for(auto &dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >=0 && nx < m && ny >=0 && ny < n && res[nx][ny] == -1){
                    res[nx][ny] = res[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return res;

    }
};