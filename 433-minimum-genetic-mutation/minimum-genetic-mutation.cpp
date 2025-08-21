class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //ACGT choices h mere pass
        //start to end 
        //mutation gene bank m bhi hona cvhaioye toh make it valid
        //choices k sath

        unordered_set<string> bankset(bank.begin(),bank.end());
        unordered_set<string>  visited;

        queue<string> q;
        q.push(startGene);
        int level = 0;

        while(!q.empty()){
            int N = q.size();

            while(N--){
                auto top = q.front();
                q.pop();

                if(top == endGene) return level;

                for(auto ch: "ACGT"){
                   
                    for(int i = 0 ; i < top.size();i++){
                        string neigh = top;
                        neigh[i] = ch;
                        if(visited.find(neigh) == visited.end() && bankset.find(neigh) != bankset.end()){
                            visited.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};