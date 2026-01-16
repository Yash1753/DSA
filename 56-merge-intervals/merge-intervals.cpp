class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        int maxi = 0;
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n ; i++){
            if(intervals[i][0] <= ans.back()[1]){
                int currMax = max(intervals[i][1],ans.back()[1] );
                ans.back()[1] = currMax;
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};