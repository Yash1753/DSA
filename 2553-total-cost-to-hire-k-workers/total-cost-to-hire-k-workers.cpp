class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //cost array -> cost[i] vo value h tohire ith worker
        //k worker krne h hire
        //har session m lowest cost -'. tie p index se krlo
        //heap size < candidate toh choose lowest worker
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;

        long long sum = 0;
        int hired = 0;
        int i = 0 , j = n-1;
        while(hired < k){
            while(pq1.size() < candidates && i <=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size() < candidates && i <=j){
                pq2.push(costs[j]);
                j--;
            }

            int min1 = pq1.size()>0 ? pq1.top() : INT_MAX;
            int min2 = pq2.size()>0 ? pq2.top() : INT_MAX;

            if(min1 <= min2){
                sum+= min1;
                pq1.pop();
                
            }else{
                sum+= min2;
                pq2.pop();
            }

            hired++;
        }

        return sum;
        
    }
};