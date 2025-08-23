#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = (int)edges.size();
        vector<int> globalVisited(n, 0);     // visited across all walks
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            if (globalVisited[i]) continue;

            int u = i;
            unordered_map<int,int> seenAtStep; // node -> step index within this walk
            int step = 0;

            // Walk forward until we hit -1 or a globally visited node
            while (u != -1 && !globalVisited[u]) {
                globalVisited[u] = 1;
                seenAtStep[u] = step++;
                u = edges[u];
            }

            // If we ended on a node u that's part of the *current* walk,
            // we've found a cycle. Its length is step - seenAtStep[u].
            if (u != -1 && seenAtStep.count(u)) {
                ans = max(ans, step - seenAtStep[u]);
            }
        }
        return ans;
    }
};
