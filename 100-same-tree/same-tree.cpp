class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;               // both are null
        if (!p || !q) return false;              // one is null, the other is not
        if (p->val != q->val) return false;      // values are different

        // recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};