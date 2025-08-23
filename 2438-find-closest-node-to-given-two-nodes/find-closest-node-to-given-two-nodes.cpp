class Solution {
public:
    void walk(const vector<int>& edges, int start, vector<int>& dist) {
        int n = edges.size();
        vector<int> seen(n, 0);
        int d = 0, u = start;

        while (u != -1 && !seen[u]) {
            seen[u] = 1;
            dist[u] = d++;
            u = edges[u];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);

        walk(edges, node1, d1);
        walk(edges, node2, d2);

        int bestNode = -1;
        int bestMaxDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (d1[i] == INT_MAX || d2[i] == INT_MAX) continue;  // unreachable by one side
            int cur = max(d1[i], d2[i]);
            if (cur < bestMaxDist || (cur == bestMaxDist && i < bestNode)) {
                bestMaxDist = cur;
                bestNode = i;
            }
        }
        return bestNode;
    }
};
