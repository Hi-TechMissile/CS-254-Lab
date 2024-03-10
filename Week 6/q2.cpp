#include <bits/stdc++.h>
using namespace std;

int longestPathInDAG(int n, vector<vector<int>>& adj) {
    queue<int> next_vertices;
    vector<int> in_degree(n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            int y = adj[i][j];
            // edge from i -> y
            ++in_degree[y];
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (in_degree[i] < 1) {
            next_vertices.push(i);
        }
    }

    vector<int> dis(n + 1);
    int longest_path_length = 0;

    while (!next_vertices.empty()) {
        int v = next_vertices.front();
        next_vertices.pop();
        longest_path_length = max(longest_path_length, dis[v]);

        for (auto &y : adj[v]) {
            --in_degree[y];
            dis[y] = max(dis[y], 1 + dis[v]);
            if (in_degree[y] < 1) {
                next_vertices.push(y);
            }
        }
    }

    return longest_path_length;
}

int main() {
    freopen("input2.txt", "r", stdin);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << "The longest path in the given DAG is: " << longestPathInDAG(N, adj) << "\n\n";
    return 0;
}