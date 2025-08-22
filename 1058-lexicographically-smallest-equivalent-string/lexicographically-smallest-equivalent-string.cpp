class Solution {
public:
    string result;

    char DFS(unordered_map<char,vector<char>>&adj, char ch, vector<bool>&visited){
        visited[ch-'a'] = true;
        char minChar = ch;
        for(auto &v : adj[ch]){
            if(!visited[v-'a']){
                minChar = min(minChar, DFS(adj,v,visited));
            }
        }

        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();

        result = "";


        unordered_map<char,vector<char>>adj;

        for(int i = 0 ; i < n ; i++){
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0 ; i < m ;i++){
            vector<bool>visited(26,false);
            char ch = baseStr[i];
            result+=DFS(adj,ch,visited);
        }

        return result;

    }
};