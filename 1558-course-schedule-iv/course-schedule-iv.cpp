class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //query k sath prerequite toh prane k pura prerequiset bhi dekha pdega
        unordered_map<int,unordered_set<int>>adj;
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[v].insert(u);
        }

        for(int i = 0 ; i <  numCourses ; i++){
            for(int j = 0 ; j < numCourses ; j++){
                if(adj[j].count(i)){
                    adj[j].insert(adj[i].begin(), adj[i].end());
                }
            }
        }

        vector<bool>ans;

        for(auto &q : queries){
            int u = q[0];
            int v = q[1];

            if(adj[v].count(u)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;

    }
};