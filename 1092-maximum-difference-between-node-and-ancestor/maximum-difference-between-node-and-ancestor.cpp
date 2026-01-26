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

    int maxDiff = -1;

    void maxD(TreeNode* root, TreeNode* child){
        if(!root || !child) return;
        maxDiff = max(maxDiff, abs(root->val - child->val));

        if(child->left)maxD(root,child->left);
       if(child->right) maxD(root,child->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        

        maxD(root,root->left);
        maxD(root,root->right);

        if(root->left)maxAncestorDiff(root->left);
        if(root->right)maxAncestorDiff(root->right);

        return maxDiff;
    }
};