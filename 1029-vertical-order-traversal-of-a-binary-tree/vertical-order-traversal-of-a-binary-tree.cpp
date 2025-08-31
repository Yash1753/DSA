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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root) return {};
        map<int, map<int,multiset<int>>> mp; //hdistance -> nodes at that point //level lena pdega guru to maintain indexing

        queue<pair<TreeNode*,pair<int,int>>>q; //node -> uska horizaNTAL distance

        q.push({root,{0,0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode * node = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;


            mp[hd][lvl].insert(node->val);

            if(node->left) q.push({node->left , {hd-1,lvl+1}});
            if(node->right) q.push({node->right , {hd+1,lvl+1}});
        }

        for(auto it : mp){
            vector<int>temp;
            for(auto i : it.second){
               for(auto k : i.second){
                temp.push_back(k);
               }
            }
            ans.push_back(temp);
        }

        return ans;


    }
};