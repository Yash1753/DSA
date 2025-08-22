class Solution {
public:

    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    typedef pair<int,int>P ;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m  = image.size();
        int n  = image[0].size();

        //img[i][i] == pixel vel,, sr,sc

        vector<vector<int>> result(m, vector<int>(n,-1));
        queue<P>q;
        q.push({sr,sc});
        result[sr][sc] = color;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int i = top.first;
            int j = top.second;

            for(auto &dir: directions){
                int new_i = i+dir[0];
                int new_j = j+dir[1];

                if(new_i >=0 && new_i < m && new_j >= 0 && new_j < n && image[new_i][new_j] == image[i][j] && result[new_i][new_j] == -1){
                    result[new_i][new_j] = color;
                    q.push({new_i,new_j});
                }
            }

        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(result[i][j] == -1){
                    result[i][j] = image[i][j];
                }
            }
        }
        return result;



    }
};