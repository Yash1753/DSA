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
    void populate(TreeNode * root, priority_queue<int, vector<int>, greater<int>>&pq ){
        if(!root) return;
        pq.push(root->val);
        if(root->left) populate(root->left,pq);
        if(root->right) populate(root->right,pq);
    }

    int kthSmallest(TreeNode* root, int k) {
        //heap
        if(! root) return 0; 
        priority_queue<int, vector<int>, greater<int>>pq;
        populate(root,pq);
        while(--k){
            pq.pop();
        }

        return pq.top();

    }
};