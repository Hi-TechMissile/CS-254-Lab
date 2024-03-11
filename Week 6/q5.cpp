#include <bits/stdc++.h>
using namespace std;

// A recursive function that finds if articulation points and bridges exist using DFS traversal
void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& visited_time, vector<int>& lowest_vis_time, int& time, int parent, bool& articulation_point, bool& bridge) {
	int children = 0;
	visited[u] = true;

	// Initialize discovery time and lowest_vis_time value
	visited_time[u] = lowest_vis_time[u] = ++time;

	// Go through all adjacent vertices
	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
            if (!articulation_point || !bridge) {
                DFS(adj, v, visited, visited_time, lowest_vis_time, time, u, articulation_point, bridge);
            }

			lowest_vis_time[u] = min(lowest_vis_time[u], lowest_vis_time[v]);
			if (parent > 0 && lowest_vis_time[v] >= visited_time[u]) {
				articulation_point = true;
            }
            
            if (lowest_vis_time[v] > visited_time[u]) {
                bridge = true;
            }
		}

		// Update lowest_vis_time value of u for parent function calls.
		else if (v != parent) {
            // back-edge found
			lowest_vis_time[u] = min(lowest_vis_time[u], visited_time[v]);
        }
    }

	// If u is root of DFS tree and has two or more children, then it is definitely an articulation point.
	if (parent == 0 && children > 1) {
        articulation_point = true;
    }
}

int main() {
    freopen("input5.txt", "r", stdin);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(N + 1);
    vector<int> visited_time(N + 1), lowest_vis_time(N + 1, INT_MAX);
    bool contains_articulation_point = false, contains_bridge = false;
    int time = 0;
    DFS(adj, 1, visited, visited_time, lowest_vis_time, time, 0, contains_articulation_point, contains_bridge);

    if (contains_articulation_point) {
        cout << "The given graph consists of one or more articulation points.\n";  
    } else {
        cout << "The given graph DOES NOT contain any articulation points.\n";
    }

    if (contains_bridge) {
        cout << "The given graph consists of one or more bridges.\n";
    } else {
        cout << "The graph does not contain any bridges.\n";
    }
    
    cout << "\n";
	return 0;
}
