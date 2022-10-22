vector<vector<pair<int, int>>> G(n); // dest, weight
vector<int> dist(n, INT_MAX);

// Najkrotsza sciezka od poczatkowego wierzcholka do reszty (musza byc nieujemne)
auto Dijkstra = [&](const int src) {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({ dist[src] = 0, src });
    while (!Q.empty()) {
        auto [d, u] = Q.top(); Q.pop();
        if (d != dist[u]) continue;
        for (auto& [v, w] : G[u]) {
            if (dist[v] > d + w)
                Q.push({ dist[v] = d + w, v });
        }
    }
};
