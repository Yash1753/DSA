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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        bool toggle = false;
        while(!q.empty()){
            int N = q.size();
            vector<int>temp;
            while(N--){
                auto top = q.front(); q.pop();
                temp.push_back(top->val);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);

            }

            if(toggle) reverse(temp.begin(), temp.end());
            toggle = !toggle;
            ans.push_back(temp);
        }

        return ans;
    }
};