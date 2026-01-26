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
    void fill(TreeNode*root, vector<int>&temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            return;
        }

        fill(root->left,temp);
        fill(root->right,temp);


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1;
        vector<int>temp2;

        fill(root1,temp1);
        fill(root2,temp2);

        return temp1 == temp2;
    }
};