class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //approach simple h
        //pehle ek ds bnaege jo rhkega start_time,ProcessingTime and index
        //phir sbko currTime k sath compare krke ek min heap m push krege ab iss min Heap m processing Time and index hoga

        vector<array<int,3>> sortedTasks;
        int  n = tasks.size();
        for(int i = 0 ; i < n ; i++){
            sortedTasks.push_back({tasks[i][0], tasks[i][1],i}); //ab mere pass  h yaha teeno chhez h
        }

        //sort krna h to get in order of their arrival
        sort(begin(sortedTasks), end(sortedTasks));

        vector<int>ans;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >pq;
        long long time = 0;
        int i = 0;
        while(i < n  || !pq.empty()){
            if(pq.empty() && time < sortedTasks[i][0]){
                time = sortedTasks[i][0];
            }

            while(i<n && time >= sortedTasks[i][0]){
                pq.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }

            //ab heaps se pop
            auto curr = pq.top();
            pq.pop();

            time+= curr.first;
            ans.push_back(curr.second);

        }



        return ans;
    }
};