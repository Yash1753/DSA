class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //ye krte h
        //can turn one wheel slot
        //in deadends

        string start = "0000";
        queue<string>q;
        q.push(start);

        unordered_set<string>seen(deadends.begin(),deadends.end());

        if(seen.count(start)) return -1;
        seen.insert(start);

        int res = 0;

        while(!q.empty()){
            int N =q.size();
            while(N--){
                auto word  = q.front();q.pop();
                if(word == target) return res;

                for(int i = 0 ; i < 4 ; i++){
                    string inc = word;
                    string dec = word;
                   
                        //inc
                        inc[i] = (inc[i] == '9') ? '0' : inc[i]+1;
                        if(!seen.count(inc)){
                            q.push(inc);
                            seen.insert(inc);
                        }
                        dec[i] = (dec[i] == '0') ? '9' : dec[i]-1;
                        if(!seen.count(dec)){
                            q.push(dec);
                            seen.insert(dec);
                        }

                    
                }
            }
            res++;
        }
        return -1;
    }
};