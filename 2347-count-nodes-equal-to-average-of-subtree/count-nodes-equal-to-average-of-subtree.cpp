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
    int ans = 0;
    
    pair<int,int> helper(TreeNode* root){
        if(!root)return {0,0};

       
        auto leftSe = helper(root->left);
         auto rightSe = helper(root->right);

         int totSum = leftSe.first + rightSe.first + root->val;
         int totalCnt = leftSe.second + rightSe.second + 1;

         int avg = totSum/totalCnt;
         if(avg == root->val) ans++;

         return {totSum,totalCnt};


        
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);

        return ans;
    }
};