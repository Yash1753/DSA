class Solution {
public:
    int n,m;
    vector<vector<int>>t;
    int solve(int i, int j, vector<vector<int>>&grid){
        if( i >= n || j >= m) return 1e9;
        if(t[i][j] != -1) return t[i][j];
        if(i == n-1 && j == m-1){
            if(grid[i][j] < 0){
                return abs(grid[i][j]) + 1;
            }else{
                return 1;
            }
        }

        int right = solve(i,j+1,grid);
        int down = solve(i+1 , j, grid);

        int result = min(right,down) - grid[i][j];

        if(result <= 0 ) return t[i][j]=1;
        return t[i][j] = result;
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        t.resize(n,vector<int>(m,-1));
        return  solve(0,0,dungeon);
    }
};