#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Return {farthest_node, distance} from a given start using DFS on a tree
    pair<int,int> farthest(int u, int parent, const vector<vector<int>>& adj) {
        pair<int,int> best = {u, 0};
        for (int v : adj[u]) {
            if (v == parent) continue;
            auto got = farthest(v, u, adj);
            if (got.second + 1 > best.second) {
                best = {got.first, got.second + 1};
            }
        }
        return best;
    }

    // Diameter of a tree given its adjacency
    int treeDiameter(const vector<vector<int>>& adj) {
        if (adj.empty()) return 0;                  // single node (no edges)
        auto a = farthest(0, -1, adj);              // farthest from 0
        auto b = farthest(a.first, -1, adj);        // farthest from a
        return b.second;                             // number of edges on the longest path
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = (int)edges1.size() + 1;
        int n2 = (int)edges2.size() + 1;

        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto &e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        int d1 = treeDiameter(adj1);
        int d2 = treeDiameter(adj2);

        // Radius = ceil(d/2) = (d+1)/2 with integer math
        int r1 = (d1 + 1) / 2;
        int r2 = (d2 + 1) / 2;

        // Best possible diameter after connecting any node of T1 to any node of T2
        int merged = r1 + r2 + 1;

        return max({d1, d2, merged});
    }
};
