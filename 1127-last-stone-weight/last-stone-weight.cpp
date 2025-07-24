class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //maxheap leke upar k 2 element use krte
        priority_queue<int>pq;

        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            auto top = pq.top();
            pq.pop();

            auto sTop = pq.top();
            pq.pop();

            if(top-sTop != 0){
                pq.push(top-sTop);
            }
        }
        if(!pq.size()) return 0;
        return pq.top();
    }
};