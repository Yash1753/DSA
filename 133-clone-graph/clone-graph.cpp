/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void dfs(Node * copy_clone, Node * node, unordered_map<Node*,Node*>&mp ){
        for(auto &n : node->neighbors ){
            if(mp.find(n) == mp.end()) {
                //mtlb exist nhi h
                Node * clone = new Node(n->val);
                mp[n] = clone;
                copy_clone->neighbors.push_back(clone); 
                dfs(clone,n,mp);
            }else{
                copy_clone->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        //deep copy deni h toh maintain krne h nodes'
        unordered_map<Node*,Node*>mpp;

        Node* copy_clone = new Node(node->val);
        mpp[node] = copy_clone;
        dfs(copy_clone, node, mpp);

        return copy_clone;
    }
};