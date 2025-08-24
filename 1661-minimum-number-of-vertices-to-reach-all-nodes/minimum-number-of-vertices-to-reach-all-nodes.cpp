class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>ind(n);

        for(auto &edge : edges){
            ind[edge[1]] = true;
        }

        vector<int>result;

        for(int i = 0 ; i < n ; i++){
            if(!ind[i]) result.push_back(i);
        }

        return result;
    }
};