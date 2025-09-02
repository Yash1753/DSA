class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //classic bfs based 
        //multisource as ek tuime p chl rhe
        vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};

        //0 is empty
        //1 is fresh
        //2 is rotten

        int m = grid.size();
        int n = grid[0].size();

        int time = 0;
        int freshOranges = 0;
        queue<pair<int,int>> q;
        //inset staring points in q
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        //lets traverse
        while(!q.empty()){
            //min wise h level order
            int N = q.size();
            while(N--){
                auto front = q.front();q.pop();
                int x = front.first;
                int y = front.second;

                for(auto &dir : directions){
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx >= 0 && nx < m && ny >=0 && ny < n && grid[nx][ny] == 1){
                        freshOranges--;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }

        if(freshOranges == 0) return time > 0 ?time-1:0;
        return -1;

    }
};