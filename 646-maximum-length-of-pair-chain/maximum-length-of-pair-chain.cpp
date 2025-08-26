class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int m = pairs[0].size();

        auto lambda = [&](vector<int>&v1, vector<int>&v2){
            return v1[1]< v2[1];
        };

        sort(pairs.begin(), pairs.end(), lambda);

         int ans = 0;
        int lastEnd = INT_MIN;               // end of the last chosen pair
        for (const auto& p : pairs) {
            if (p[0] > lastEnd) {            // strictly increasing: a < b
                ++ans;
                lastEnd = p[1];
            }
        }
        return ans;
    }
};