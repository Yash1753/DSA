class Solution {
public:

    void DFS(vector<vector<int>>& graph, int u, int source ,vector<vector<int>>&result,vector<int>&temp ){
        temp.push_back(u);

        if(u == source){
            result.push_back(temp);
        }else{
            for(auto &v : graph[u]){
                DFS(graph,v,source, result,temp);
            }
        }

        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>temp;    
        int n = graph.size();

        DFS(graph, 0, n-1, result,temp);

        return result;
    }
};