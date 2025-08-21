class Solution {
public:
vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
typedef pair<int,int> P;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //emp -> . and wall = +
        //four direction movement wall p nhi jana
        //exiot -> emp on border

        int n = maze.size();
        int m = maze[0].size();
        queue<P> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int level = 0;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                if((temp != make_pair(entrance[0],entrance[1])) && (i == 0 || i == n-1 || j==0 || j==m-1)  ){
                    return level;
                }

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >=0 && new_i < n && new_j >=0 && new_j<m && maze[new_i][new_j] != '+'){
                        q.push({new_i,new_j});
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            level++;
        }

        return -1;


    }
};