/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      void build(TreeNode* u, unordered_map<int, vector<int>>& g) {
        if (!u) return;
        if (u->left) {
            g[u->val].push_back(u->left->val);
            g[u->left->val].push_back(u->val);
            build(u->left, g);
        }
        if (u->right) {
            g[u->val].push_back(u->right->val);
            g[u->right->val].push_back(u->val);
            build(u->right, g);
        }
        if (!g.count(u->val)) g[u->val] = {};
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root) return {};
        unordered_map<int, vector<int>> adj;
        build(root, adj);

        int min = 0;
        queue<int>q;
        q.push(start);
        unordered_set<int> seen;
        seen.insert(start);
        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto top = q.front();
                q.pop();
                seen.insert(top);
                for(auto &v : adj[top]){
                    if(seen.count(v) == 0){
                        q.push(v);
                    }
                }
            }
            min++;
        }

        return min-1;
    }
};