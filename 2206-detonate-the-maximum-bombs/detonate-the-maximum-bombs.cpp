class Solution {
public:

    void dfs(int u ,  unordered_map<int,vector<int>>&adj, unordered_set<int>&st){
        st.insert(u);
        for(auto &v : adj[u]){
            if(st.count(v) == 0){
                dfs(v,adj,st);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>>adj;

        for(int i = 0 ; i < size(bombs) ; i++){
            for(int j = 0 ; j < size(bombs) ; j++){
                if(i == j) continue;

                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];

                long long dist = (pow((x1-x2),2) + pow((y1-y2),2));

                if((long long)r1*r1 >= dist){
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;

        unordered_set<int>visited;

        for(int i = 0 ; i < size(bombs) ; i++){
            dfs(i,adj,visited);
            int cnt = size(visited);
            result = max(result,cnt);
            visited.clear();
        }

        return result;

    }
};