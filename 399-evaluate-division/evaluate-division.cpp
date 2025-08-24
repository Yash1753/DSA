class Solution {
public:
typedef pair<string,double>P;
    void dfs( unordered_map<string,vector<P>>&adj, string src, string dest,unordered_set<string> &st, double product, double &ans ){
        if(st.find(src) != st.end()) return;
        st.insert(src);

        if(src == dest){
            ans = product;
            return;
        }

        for(auto &vec : adj[src]){
            auto v = vec.first;
            auto mul = vec.second;
                 dfs(adj,v,dest,st,product*mul , ans);
        
        }

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //ek graph banle wieght result as nodes phir traverse krte multiple krde for each query

       int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i<n; i++) {
            
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});        //To handle a/c
            adj[v].push_back({u, 1.0/val});    //To handle c/a
        }
        //graph bngyi ab check maarte
        vector<double>result;

       for(auto &query : queries) {
            
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                
                dfs(adj, src, dst, visited, product, ans);
                
            }
            
            result.push_back(ans);
            
        }

        return result;
    }
};