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
    int maxLevelSum(TreeNode* root) {
        if(!root->left && !root->right) return 1;

        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        int lv = 1;
        q.push({root,1});

        while(!q.empty()){
            int N = q.size();
            int sum = 0;
            while(N--){
                auto top = q.front();
                q.pop();
                auto node = top.first;
                auto level = top.second;
                sum += node->val;
                if(node->left)q.push({node->left, level+1});
                if(node->right)q.push({node->right, level+1});
            }

            ans.push_back(sum);
        }

        int maxi = *max_element(ans.begin(), ans.end());

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == maxi){
                lv = i;
                break;
            }
        }
        return lv+1;

    }
};