class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //label ->graph
        //room o unlokced visit qall with key vuisist and find keys 
        int n = rooms.size();
        unordered_map<int,vector<int>>adj;

        queue<int>q;
        q.push(0);
        vector<bool>visited(n,false);
        int cnt = 1;
        visited[0] = true;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(auto &v : rooms[top]){
                if(!visited[v]){
                    q.push(v);
                    cnt++;
                    visited[v] = true;
                }
            }

            
        }

        return cnt == n;


    }
};