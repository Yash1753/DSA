class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;

        for(auto &it : piles)pq.push(it);

        while(k>0){
            auto top = pq.top();
            pq.pop();
            top = ceil((double)top/2.0);
            pq.push(top);
            k--;
        }

        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};