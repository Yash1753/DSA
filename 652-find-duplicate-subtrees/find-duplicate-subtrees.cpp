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
    string helper(TreeNode*root, unordered_map<string,int>&mpp, vector<TreeNode*>&ans){
        if(!root) return "N";

        string key = to_string(root->val) + "_" + helper(root->left,mpp,ans) + "_" + helper(root->right,mpp,    ans);
        if(mpp[key] == 1){
            ans.push_back(root);
        }

        mpp[key]++;

        return key;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mpp;
        vector<TreeNode*>ans;

        helper(root,mpp,ans);
        return ans;
    }
};