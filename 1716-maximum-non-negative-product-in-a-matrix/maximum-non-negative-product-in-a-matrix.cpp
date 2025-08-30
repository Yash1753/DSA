class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        //khali positive toh noraml ho ajta
        //neg m take care ki pichla max, min rkhna hoga if curr neg h toh min bhi neg h toh pos hojaye ga and have to compare then
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<ll,ll>>> t(n, vector<pair<ll,ll>>(m));
        t[0][0] = {grid[0][0], grid[0][0]};

        for(int i = 1 ; i < n ; i++){
            t[i][0] = make_pair(t[i-1][0].first *grid[i][0], t[i-1][0].second *grid[i][0]);
        }
         for(int i = 1 ; i < m ; i++){
            t[0][i] = make_pair(t[0][i-1].first *grid[0][i], t[0][i-1].second *grid[0][i]);
        }

        for(int i = 1 ; i < n ; i++ ){
            for(int j = 1 ; j < m ; j++){
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                ll maxV = max({upMax * grid[i][j] , upMin * grid[i][j], leftMax * grid[i][j] , leftMin * grid[i][j]});
                ll minV = min({upMax * grid[i][j] , upMin * grid[i][j], leftMax * grid[i][j] , leftMin * grid[i][j]});

                t[i][j] = make_pair(maxV,minV);
            }
        }

        ll ans = t[n-1][m-1].first;
        if(ans < 0) return -1;
        return ans%MOD;


    }
};