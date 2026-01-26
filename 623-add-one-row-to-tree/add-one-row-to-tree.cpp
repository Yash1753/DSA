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
    TreeNode* add(TreeNode* &root, int val, int depth, int curr){
        if(!root) return NULL;

        if(curr == depth-1){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;

            return root;
        }

        if(root->left) add(root->left,val,depth,curr+1);
        if(root->right) add(root->right,val,depth,curr+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        int curr = 1;
        return add(root,val,depth,curr);

    }
};