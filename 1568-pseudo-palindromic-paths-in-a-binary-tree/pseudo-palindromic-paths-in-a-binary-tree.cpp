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
    int cnt = 0;

    void helper(TreeNode*root, vector<int>&temp){
        if(!root) return;

        temp[root->val]++;
        int oddfreq = 0;

        if(!root->left && !root->right){
            for(int i = 1 ; i <= 9 ; i++){
            if(temp[i]%2) oddfreq++;

        }

        if(oddfreq <=1) cnt++;
        }
        

        helper(root->left,temp);
        helper(root->right,temp);

        temp[root->val]--;


    }

    int pseudoPalindromicPaths (TreeNode* root) {
        //main thing here will be atmax 1 odd element can exist in path
        vector<int>temp(10,0);
        helper(root,temp);
        return cnt;
    }
};