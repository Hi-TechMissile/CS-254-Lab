#include <bits/stdc++.h>
using namespace std;

// assuming 1-based indexing of graph vertices
bool doesNotContainCycle(int n, vector<vector<int>>& adj) {
    queue<int> next_vertices;
    vector<int> in_degree(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (auto& x : adj[i]) {
            ++in_degree[x];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] < 1) {
            next_vertices.push(i);
        }
    }

    bitset<200001> vis;

    while (!next_vertices.empty()) {
        int v = next_vertices.front();
        next_vertices.pop();
        vis[v] = true;

        for (auto &y : adj[v]) {
            --in_degree[y];
            if (in_degree[y] < 1) {
                next_vertices.push(y);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("input4.txt", "r", stdin);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (doesNotContainCycle(N, adj)) {
        cout << "The given DAG is free of any cycles.\n";
    } else {
        cout << "The given DAG consists of one or more cycles.\n";
    }

    cout << "\n";
    return 0;
}