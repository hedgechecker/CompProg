#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;   // adjacency list
vector<bool> visited;

// Recursive DFS to collect nodes of one component
void dfs(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, component);  // recursive step
        }
    }
}

// Decomposes the graph into connected components
vector<vector<int>> decomposeGraph(int n) {
    visited.assign(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m;   // number of nodes and edges
    adj.assign(n, {});

    // undirected graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto components = decomposeGraph(n);

    cout << "Number of components: " << components.size() << "\n";
    for (auto& comp : components) {
        for (int x : comp) cout << x << " ";
        cout << "\n";
    }
}
