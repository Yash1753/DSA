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
    vector<vector<int>> ans;
    void levelOrder(TreeNode * root){
        if(!root) return;
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        int cnt = 0;

        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();

            if(front == NULL){
                if(cnt%2){
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
                cnt++;
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                temp.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

        }



    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrder(root);
        return ans;
    }
};