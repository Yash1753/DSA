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
    unordered_map<TreeNode*,TreeNode*>mpp;
    void mapp(TreeNode *root){
        if(!root) return;

        if(root->left) mpp[root->left] = root;
        mapp(root->left);

        if(root->right) mpp[root->right] = root;
        mapp(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //map the parent and find ans
        mapp(root);

        //it is mapped
        //make a queue

        queue<TreeNode*>q;
        unordered_set<int>st;
        q.push(target);
        st.insert(target->val);

        while(!q.empty()){
            int n = q.size();
            if(k == 0) break;
            
            while(n--){
                auto top = q.front();
                q.pop();

                if(top->left && st.find(top->left->val) == st.end()){
                    q.push(top->left);
                    st.insert(top->left->val);
                }

                if(top->right && st.find(top->right->val) == st.end()){
                    q.push(top->right);
                    st.insert(top->right->val);
                }

                //do for parent as well

                if(mpp.count(top) && st.find(mpp[top]->val) == st.end()){
                    q.push(mpp[top]);
                    st.insert(mpp[top]->val);
                }
            }
            k--;
        }

        vector<int>res;
        while(!q.empty()){
            auto top = q.front();q.pop();
            res.push_back(top->val);
        }
        return res;
    }
};