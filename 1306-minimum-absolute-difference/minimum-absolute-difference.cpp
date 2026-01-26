class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        //find minimum absoulute diff
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        int n = arr.size();
        int mindiff = INT_MAX;
        for(int i = 0 ; i < n -1 ; i++){
            mindiff = min(mindiff, abs(temp[i+1] - temp[i]));
        }
        vector<vector<int>>ans;
        for(int i = 0 ; i < n -1 ; i++){
            if(abs(temp[i] - temp[i+1]) == mindiff){
                ans.push_back({temp[i],temp[i+1]});
            }
        }

        return ans;


    }
};