// DFS (graph traversal)
// time complexity: O(n), space: O(n)

vector<vector<int>> G(n);
vector<bool> visited(n);

function<void(int)> DFS = [&](int u) {
    visited[u] = true;
    for (auto v : G[u])
        if (!visited[v])
            DFS(v);
};
