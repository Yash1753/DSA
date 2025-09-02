class Solution {
public:

    //start krna image[sr][sc]p and change color har adj p same jkaam krna 
    //directions bna lege 
    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m  = image.size();
        int n  = image[0].size();
        if(image[sr][sc] == color) return image;
        queue<pair<int,int>>q; // colr - >coordinates
        q.push( {sr,sc});
        int orig  = image[sr][sc];
        vector<vector<int>> res(image.begin(),image.end());
        res[sr][sc] = color;
        while(!q.empty()){
            auto top = q.front();q.pop();
            
            int x = top.first;
            int y = top.second;

            for(auto &dir : directions){
                int x_ = x+dir[0];
                int y_ = y+dir[1];

                if(x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && image[x_][y_] == orig && res[x_][y_] != color){
                    res[x_][y_] = color;
                    //image[x][y]= -1;
                    q.push({x_,y_});
                }
            }

        }

        return res;
    }
};