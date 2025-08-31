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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level order chaiye
        if(!root) return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);
       
        while(!q.empty()){
        int N = q.size();
        vector<int>temp;
        while(N--){
            auto front = q.front();q.pop();
            temp.push_back(front->val);

            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
    }

    
};