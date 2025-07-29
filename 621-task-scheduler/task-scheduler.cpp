class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //tasks -> A to Z
        //number n
        //idle ya 1 task -> task kbhi bhi krlo but take care there is atleast n intervals betwwen them
        vector<int> mp (26,0);
        for(auto it : tasks){
            mp[it-'A']++;
        }

        int time = 0;
        priority_queue<int>pq;

        for(auto f : mp){
            if(f > 0){
                pq.push(f);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 1 ; i <= n+1 ; i++){
                if(!pq.empty()){
                    auto top = pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
                
            }

            for(auto f : temp){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time+= temp.size();
            }else{
                time += n+1;
            }
        }

        return time;
        

    }
};