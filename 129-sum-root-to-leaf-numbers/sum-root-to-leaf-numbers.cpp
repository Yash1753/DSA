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
    int sum = 0;
    void helper(TreeNode* root, string s){
        if(!root) return;

        s += to_string(root->val);
        if(!root->left && !root->right){
            sum += stoi(s);
        } 

        
        if(root->left) helper(root->left, s);
        if(root->right) helper(root->right,s);




    }

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        helper(root,"");

        
        return sum;
    }
};