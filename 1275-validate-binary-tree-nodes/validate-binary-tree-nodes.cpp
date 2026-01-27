class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,int>parent;
        unordered_map<int,vector<int>> adj;

        for(int i = 0 ; i < n ; i++){
            int node = i;
            int left  = leftChild[i];
            int right = rightChild[i];

            if(left!=-1){
                adj[node].push_back(left);
                if(parent.find(left) != parent.end()) return false;
                parent[left]=node;
            }
            if(right!=-1){
                adj[node].push_back(right);
                if(parent.find(right) != parent.end()) return false;
                parent[right]=node;
            }

        }

        //get roots if thy can can be only 1

        int root = -1;

        for(int i = 0 ; i < n ; i++){
            
            if(parent.find(i) == parent.end()){
                 if(root != -1) return false;
                 root = i;
            }
        }
        if(root == -1) return false;
        //ab root bhi hogyi
        //nwo do bfs to check my count

        queue<int>q;
        vector<bool>visited(n,false);
        q.push(root);
        visited[root] = true;
        int cnt = 1;

        while(!q.empty()){

            auto parentNode = q.front();
            q.pop();

            for(auto &v : adj[parentNode]){
                if(!visited[v]){
                    visited[v] = true;
                    cnt++;
                    q.push(v);
                }
            }
        }

        return cnt == n;
    }
};