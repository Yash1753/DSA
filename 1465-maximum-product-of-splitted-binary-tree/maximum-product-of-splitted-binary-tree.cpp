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
    long SUM = 0;
    long product = 0;
     long M = 1e9+7;
    int totalSum(TreeNode * root){
        if(!root) return 0;

        int left = totalSum(root->left);
        int right = totalSum(root->right);
        int sum = root->val + left + right;

        product = max(product, (sum * (SUM - sum)));
        return sum;
    }

    int maxProduct(TreeNode* root) {
        if(!root) return 0;

        SUM = totalSum(root);

        totalSum(root);

        return product%M;
    }
};