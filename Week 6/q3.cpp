#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<int>& visited_time, vector<int>& lowest_vis_time, stack<int>& stk, vector<bool>& stackMember, int& time) {
    
    // Initialize discovery time and lowest_vis_time value
    visited_time[u] = lowest_vis_time[u] = ++time;
    stk.push(u);
    stackMember[u] = true;

    // go through all adjacent nodes of u
    for (auto& v : adj[u]) {
        if (visited_time[v] < 0) {
            DFS(v, adj, visited_time, lowest_vis_time, stk, stackMember, time);
            lowest_vis_time[u] = min(lowest_vis_time[u], lowest_vis_time[v]);
        } else if (stackMember[v]) {
            lowest_vis_time[u] = min(lowest_vis_time[u], visited_time[v]);
        }
    }

    if (lowest_vis_time[u] == visited_time[u]) {
        while (stk.top() != u) {
            cout << stk.top() << " ";
            stackMember[stk.top()] = false;
            stk.pop();
        }
        cout << stk.top() << "\n";
        stackMember[stk.top()] = false;
        stk.pop();
    }
}

int main() {
    freopen("input3.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited_time(N + 1, INT_MAX), lowest_vis_time(N + 1, INT_MAX);
    stack<int> stk;
    vector<bool> stackMember(N + 1);
    
    cout << "The strongly connected conponents of the given DAG are as follows:\n";
    int time = 0;
    DFS(1, adj, visited_time, lowest_vis_time, stk, stackMember, time);
    cout << "\n";
    return 0;
}