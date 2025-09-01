/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void populate(TreeNode* root,unordered_map<int,vector<int>>&adj, int parent ){
        if(!root) return;

        if(parent != -1) adj[root->val].push_back(parent);
        if(root->left){
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
        }

        if(root->left)populate(root->left, adj ,root->val);
        if(root->right)populate(root->right, adj ,root->val);

    }

    void dfs(unordered_map<int,vector<int>>&adj,int target, int k, vector<int>&ans, vector<int>&v,int cnt){
        v[target] = 1;

        if(cnt == k){
            ans.push_back(target);
            return;
        }

        for(auto &node: adj[target]){
            if(v[node] == -1){
                v[node] = 1;
                
                dfs(adj,node,k,ans,v,cnt+1);

            }
        }

        

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;
        if(!root) return {};
        vector<int>ans;
        populate(root,adj,-1);
       /*  for(auto it : adj){
            for(auto i : it.second){
                cout << it.first << "->" << i << " ";
            }
            cout << endl;
        } */

        //populate hoigya shi
        vector<int>visited(501,-1);
        dfs(adj,target->val,k,ans,visited,0);
        return ans;
    }
};