class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>> directions{{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<P>q;
        vector<vector<int>> height(n, vector<int>(m,-1));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

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

                    if(new_i >=0 && new_i <n && new_j>=0 && new_j < m && height[new_i][new_j] == -1){
                        q.push({new_i, new_j});
                        height[new_i][new_j] = height[i][j] +1;
                    }
                }


            }
        }

        return height;



    }
};