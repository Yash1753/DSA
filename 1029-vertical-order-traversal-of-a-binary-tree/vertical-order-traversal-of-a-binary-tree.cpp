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
        //queue
        queue<pair<TreeNode*, pair<int,int>>> q;
        //ans store
        vector<vector<int>>ans;
        //ek map col,row,node k liye

        map<int, map<int,multiset<int>>> mp;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto front  = q.front();
            q.pop();
            TreeNode* node = front.first;
            auto coordinate = front.second;
            auto &row = coordinate.first;
            auto& col = coordinate.second;
            mp[col][row] .insert(node->val);
            if(node->left)q.push({node->left,{row+1,col-1}});
            if(node->right)q.push({node->right,{row+1,col+1}});

        }

        //store
        for(auto it : mp){
            vector<int>temp;
            auto &colMap = it.second;
            for(auto colMapit : colMap){
                auto& Mset = colMapit.second;
                temp.insert(temp.end(), Mset.begin(), Mset.end());
            }

            ans.push_back(temp);
        }


        return ans;
    }
};