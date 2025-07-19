/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";

        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            auto front = q.front();q.pop();

            if(!front) s.append("#,");
            else{
                s.append(to_string(front->val) +',');
            }

            if(front!= NULL){
                q.push(front->left);
                q.push(front->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0 ) return NULL;
        stringstream s(data);

        string str;
        getline(s,str,',');

        TreeNode * root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();q.pop();
            getline(s,str,',');

            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode * leftN = new TreeNode(stoi(str));
                node->left = leftN;
                q.push(leftN); 
            }

            getline(s,str,',');

            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode * rightN = new TreeNode(stoi(str));
                node->right = rightN;
                q.push(rightN); 
            }



        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));