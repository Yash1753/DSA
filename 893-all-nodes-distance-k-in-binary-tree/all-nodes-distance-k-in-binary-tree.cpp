/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:

    void markParent(TreeNode*root, unordered_map<TreeNode*,TreeNode*> &track_parent){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front->left){
                track_parent[front->left] = front;
                q.push(front->left);
            } 
            if(front->right){
                track_parent[front->right] = front;
                q.push(front->right);
            } 
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>track_parent;
        markParent(root,track_parent);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target] = true;
        int cnt = 0;

        while(!q.empty()){
            int size = q.size();
            if(cnt++ == k) break;
            for(int i = 0 ; i <size; i++){
                auto front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if(front->right && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if(track_parent[front] && !visited[track_parent[front]]){
                    visited[track_parent[front]] = true;
                    q.push(track_parent[front]);
                }
            }
        }

        vector<int>ans;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it->val);
        }

        return ans;
    }
};