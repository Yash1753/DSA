class Solution {
public:
//kind of unit wieght toh bfs work krjayega
    int n;
    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
           if( n==0 || grid[0][0] != 0) return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        int len = 1;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto front = q.front();q.pop();
                int x = front.first;
                int y = front.second;

                if(x==n-1&& y == n-1) return len;
                for(auto &dir : directions){
                    int nx = x+dir[0];
                    int ny = y+dir[1];

                    if(nx >=0 && nx < n && ny>=0 && ny < n && grid[nx][ny] == 0){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            len++;
           
        }

        return -1;
    }
};