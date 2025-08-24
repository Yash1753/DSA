class Solution {
public:
    bool isSimilar(string&s1, string&s2){
        int n = s1.length();

        int diff = 0;

        for(int i = 0 ; i < n ; i++){
            if(s1[i] != s2[i]) diff++;
        }

        return diff<=2;
    }

    void DFS(int i ,  unordered_map<int,vector<int>>&adj, vector<bool>&visited){
        visited[i] = true;

        for(auto &v : adj[i] ){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>>adj;

        for(int i = 0 ; i < strs.size() ; i++){
            for(int j = i+1 ; j < strs.size(); j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool>visited(strs.size() , false);
        for(int i = 0 ; i < strs.size() ; i++){
            if(!visited[i]){
                DFS(i,adj,visited);
                cnt++;
            } 
        }

        return cnt;


    }
};