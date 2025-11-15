#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        unordered_map<int, vector<int>> mp;
        mp.reserve(n*2);

        for (int i = 0; i < n; ++i) mp[nums[i]].push_back(i);

        int best = INT_MAX;
        for (auto &p : mp) {
            const vector<int>& v = p.second;
            if (v.size() < 3) continue;
            // v is already in increasing order of indices
            for (size_t i = 2; i < v.size(); ++i) {
                int cur = 2 * (v[i] - v[i-2]);
                if (cur < best) best = cur;
            }
        }

        return (best == INT_MAX) ? -1 : best;
    }
};
