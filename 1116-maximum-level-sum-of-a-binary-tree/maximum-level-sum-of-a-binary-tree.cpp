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
public://best level and curr level use krega to make it even better
    int maxLevelSum(TreeNode* root) {
        if(!root->left && !root->right) return 1;

        queue<TreeNode*>q;
        vector<int>ans;
        int lv = 1;
        int tot = INT_MIN;
        q.push(root);
        int bstlvl =1 ;

        while(!q.empty()){
            int N = q.size();
            int sum = 0;
            while(N--){
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            if(tot < sum){
                tot = sum;
                bstlvl = lv;
                //if(q.empty())lv = q.front().second ;
            }
            lv++;
        }
        


      /*   int maxi = *max_element(ans.begin(), ans.end());

        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == maxi){
                lv = i;
                break;
            }
        } */
        return bstlvl;

    }
};