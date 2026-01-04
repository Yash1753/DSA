class TreeAncestor {
public:
//binary lfiting lgani pdegi
    vector<vector<int>>P;
    TreeAncestor(int n, vector<int>& parent) {
        P.resize(20,vector<int>(parent.size(),-1)); //20 as log range le rhe for highest number

        //fill the first row
        for(int i = 0 ; i  < parent.size() ; i++){
            P[0][i] = parent[i];
        }
        //for the rest of rows

        for(int i = 1 ; i < 20; i++ ){
            for(int j = 0 ; j  < parent.size() ; j++){
                int above = P[i-1][j];
                if(above!=-1){
                    P[i][j] = P[i-1][above];
                }
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0 ;i  < 20 ; i++ ){
            if(k & (1<<i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */