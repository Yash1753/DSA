class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();

        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i; 
        }

        function<int(int)> find = [&](int x){
            if(x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        };

        auto Union = [&](int x, int y){
            int X = find(x);
            int Y = find(y);

            if(X != Y){
                if(rank[X] > rank[Y]){
                    parent[Y] = X;
                }else if(rank[X] < rank[Y]){
                    parent[X] = Y;
                }else{
                    parent[X] = Y;
                    rank[Y]++;
                }
            }
        };

        unordered_map<int, priority_queue<char,vector<char>, greater<char>  >>mp;

        for(auto &it : pairs){
            Union(it[0],it[1]);
        }

        for(auto i = 0 ; i < n ; i++){
            int par = find(i);
            mp[par].push(s[i]);
        }

        string ans = "";
        for(int i = 0 ; i < n ; i++){
            int par = find(i);
            ans.push_back(mp[par].top());
            mp[par].pop();
        }
        return ans;
    }
};