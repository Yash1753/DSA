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
void helper(TreeNode* root, string s, vector<string>&ans){
    if(!root) return;

   s+= to_string(root->val);
   if(root->left) helper(root->left,s+"->",ans);
   if(root->right) helper(root->right,s+"->",ans);
   if(!root->left && !root->right) ans.push_back(s);
}
    vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>ans;
    helper(root,"",ans);
    return ans;        
    }
};