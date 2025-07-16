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
    int maxi = INT_MIN;

    int height(TreeNode * root){
        if(!root) return 0;
        int lh = max(height(root->left),0);
        int rh = max(height(root->right),0);

        maxi = max(maxi, lh+rh+root->val);

        return max(lh,rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        height(root);
        return maxi;
    }
};