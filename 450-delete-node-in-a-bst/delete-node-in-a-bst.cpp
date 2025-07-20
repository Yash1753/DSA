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
    TreeNode* maxValue(TreeNode* root){
        if(!root) return NULL;

        TreeNode * temp = root;
        while(temp->right){
            temp = temp->right;
        }

        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key){
            //delete start 
            //leaf
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            }else if(root->left && !root->right){
                TreeNode * node = root->left;
                delete root;
                return node;
            }else if(!root->left && root->right){
                TreeNode * node = root->right;
                delete root;
                return node;
            }else{
                TreeNode* maxi = maxValue(root->left);
                root->val = maxi->val;
                root->left = deleteNode(root->left,maxi->val);
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }

        return root;
    }
};