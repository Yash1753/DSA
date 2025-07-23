class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int>pq;
        for(auto it:piles){
            pq.push(it);
        }

        while(k--){
            auto front = pq.top();
            pq.pop();

            front = front-front/2;

            pq.push(front);
        }

        while(!pq.empty()){
            auto front  = pq.top();
            pq.pop();

            sum+= front;
        }


        return sum;
    }
};