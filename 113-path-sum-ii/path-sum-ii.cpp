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
    vector<vector<int>>ans;
    

    void helper(TreeNode* root, int targetSum, vector<int>&temp){
        if(!root->left && !root->right){
            targetSum-=root->val;
            temp.push_back(root->val);

            if( targetSum == 0){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }

        //going left
        temp.push_back(root->val);

        if(root->left)helper(root->left,targetSum-root->val,temp);
        if(root->right)helper(root->right,targetSum-root->val,temp);

        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        if(!root) return {};
        helper(root,targetSum,temp);
       
        return ans;
    }
};