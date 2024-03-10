#include <bits/stdc++.h>
using namespace std;

// Function to return list containing vertices in Topological order.
vector<int> topoSort(int n, vector<vector<int>>& adj) {
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

    vector<int> sorted_graph;
    while (!next_vertices.empty()) {
        int v = next_vertices.front();
        next_vertices.pop();

        sorted_graph.push_back(v);

        for (auto &y : adj[v]) {
            --in_degree[y];
            if (in_degree[y] < 1) {
                next_vertices.push(y);
            }
        }
    }

    return sorted_graph;
}

int main() {
    freopen("input1.txt", "r", stdin);
    int V, E;
    cin >> E >> V;

    vector<vector<int>> adj(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topoSort(V, adj); 
    cout << "The topological sorting of the given graph is:\n";
    for (auto& node : res) {
        cout << node << " ";
    }
    cout << "\n\n";
    return 0;
}