class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<P>q;
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        int minute = 0;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >=0 && new_i < n && new_j >=0 && new_j<m && grid[new_i][new_j] == 1){
                        q.push({new_i,new_j});
                        grid[new_i][new_j] = 2;
                        fresh--;
                    }
                }

            }

            minute++;
        }

        if(fresh == 0){
            return minute-1;
        }

        return -1;
    }
};