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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;

        TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

        if(!leftN && !rightN) return NULL;
        if(!leftN) return rightN;
        if(!rightN) return leftN;

        return root;

    }
};