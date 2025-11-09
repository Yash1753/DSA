class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        //land -> 0
        //water ->1
        //height non-neg adn water height = 0;
        //e cell adjancent diff 1,0
        vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>>height(m,vector<int>(n,-1));
        //If the cell is a water cell, its height must be 0. very imp
        queue<pair<int,int>>q;
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isWater[i][j]){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();q.pop();
                int x =top.first;
                int y =top.second;

                for(auto &dir : directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(nx>=0 && ny>=0 && nx < m && ny < n && height[nx][ny] == -1 ){
                        height[nx][ny] = height[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return height;
    }
};