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
    int maxSum = INT_MIN;
    int solve(TreeNode * root){
        if(!root) return  0;
        int lh = max(solve(root->left),0); // negative path ko negl;ect krdege
        int rh = max(solve(root->right),0);

        maxSum = max(maxSum, lh+rh+root->val);
        return max(lh,rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
     if(!root) return 0;
     solve(root);
     return maxSum;   
    }
};