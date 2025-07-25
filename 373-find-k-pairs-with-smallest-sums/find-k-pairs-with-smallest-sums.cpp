class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n  =size(nums1);
        int m  =size(nums2);
        //maintain visisted to avoid duplicates
        set<pair<int,int>>s;
        //min heap
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>>ans;
        int sum = nums1[0] + nums2[0];
        pq.push({sum,{0,0}});
        s.insert({0,0});

        while(k-- && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});

            if(j+1 < m && s.find({i,j+1}) == s.end() ){
                pq.push({nums1[i] + nums2[j+1] , {i,j+1}});
                s.insert({i,j+1});
            }

            if(i+1 < n && s.find({i+1,j}) == s.end()){
                  pq.push({nums1[i+1] + nums2[j] , {i+1,j}});
                  s.insert({i+1,j});
            }

        }
        return ans;
    }
};