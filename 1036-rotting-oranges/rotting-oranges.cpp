class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       vector<pair<int,int>>directions{{1,0},{0,1},{-1,0},{0,-1}};

       int m = grid.size(); 
       int n = grid[0].size();

       queue<pair<int,int>>q;
       int fresh = 0;
       for(int i = 0 ; i < m ;i++){
        for(int j = 0 ; j < n  ; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }else if(grid[i][j] == 1) fresh++;
        }
       } 

       //pre-processed que and count
        int time = 0;
       while(!q.empty()){
        int N = q.size();
        while(N--){
            auto top = q.front();q.pop();
            int x = top.first;
            int y = top.second;

            for(auto &dir : directions){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx>=0 && nx <m && ny>=0 && ny<n && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx,ny});
                }
            }
            
        }
        time++;
       }

       if(!fresh) return time>0 ? time-1 : 0;
       return -1;
    }
};