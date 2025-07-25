class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        //ek vector containing bboth first and second

        vector<pair<int,int>> vec(n);

        for(int i = 0 ; i<n;i++ ){
            vec.push_back({nums1[i],nums2[i]});
        }

        //sort 
        sort(begin(vec),end(vec), [&](auto &a,auto &b){
            return a.second>b.second;
        });

        //m,in heap
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum = 0;
        //for first k-1 element 
        for(int i = 0 ; i<k ; i++){
            sum+= vec[i].first;
            pq.push(vec[i].first);
        }

        long long int result = sum * vec[k-1].second;

        for(int i = k ; i < n ; i++){
            sum += vec[i].first - pq.top();
            pq.pop();

            pq.push(vec[i].first);

            result = max(result, sum * vec[i].second);
        
        
        }

        return result;

    }
};