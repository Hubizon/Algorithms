// Check whether a graph has a cycle
// time complexity: O(n), space: O(n)

vector<vector<int>> G(n);

// in an undirected graph:
vector<bool> vis(n);

function<bool(int, int)> DFS = [&](int u, int p) {
    vis[u] = true;
    for (auto v : G[u]) {
        if (vis[v] && v != p) return true;
        if (!vis[v])
            if (DFS(v, u)) return true;
    }
    return false;
};

for (int i = 0; i < n; i++)
    if (!vis[i])
        if (DFS(i, -1)) return true;


// in a directed graph:
vector<int> vis(n);

function<bool(int)> DFS = [&](int u) {
    vis[u] = 1;
    for (auto v : G[u]) {
        if (vis[v] == 1) return true;
        if (vis[v] == 0)
            if (DFS(v)) return true;
    }
    vis[u] = 2;
    return false;
};

for (int i = 0; i < n; i++)
    if (!vis[i])
        if (DFS(i)) return true;
