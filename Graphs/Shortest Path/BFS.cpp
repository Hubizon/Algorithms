// BFS (shortest path from source to every other node, all weights being 1)
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<int>> G(n);
vector<int> dist(n, INT32_MAX);

auto BFS = [&](const int src) {
    dist[src] = 0;
    queue<int> Q; Q.push(src);
    while (Q.size()) {
        auto u = Q.front(); Q.pop();
        for (auto& v : G[u]) {
            if (dist[v] == INT32_MAX) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
};