class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int>pq;
        for(auto it : stones) pq.push(it);

        while(pq.size() > 1){
            auto top = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            if(top-second > 0){
                pq.push(top-second);
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};