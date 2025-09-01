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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        //if(!root) return NULL;
        if(!root || root == p || root == q) return root;

        //if(p == q) return p;

        TreeNode* left = solve(root->left, p ,q);
        TreeNode* right = solve(root->right, p ,q);

        if(!left && !right) return NULL;
        if(left && !right) return left;
        if(!left && right) return right ;
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        return solve(root,p,q );
    }
};