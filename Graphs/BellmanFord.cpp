// Najkrotsza sciezka od poczatkowego wierzcholka do reszty (moga byc ujemne)

// returns true if there is a negative cycle - Edges
vector<tuple<int, int, int>> E; // source, dest, weight
vector<int> dist(n, INT_MAX);
auto BellmanFord = [&](const int src) {
    dist[src] = 0;
    bool isRelaxed = true;
    for (int i = 0; i < n && isRelaxed; i++) {
        isRelaxed = false;
        for (auto& [s, d, w] : G) {
            if (dist[s] != INT_MAX && dist[d] > dist[s] + w) {
                dist[d] = dist[s] + w;
                isRelaxed = true;
            }
        }
    }
    return isRelaxed;
};

// returns true if there is a negative cycle - Graph
vector<vector<pair<int, int>> G; // dest, weight
vector<int> dist(n, INT_MAX);
auto BellmanFord = [&](const int src) {
    dist[src] = 0;
    bool isRelaxed = true;
    for (int i = 0; i < n && isRelaxed; i++) {
        isRelaxed = false;
        for (auto& g : G) {
            for (auto [d, w] : g) {
                if (dist[s] != INT_MAX && dist[d] > dist[i] + w) {
                    dist[d] = dist[i] + w;
                    isRelaxed = true;
                }
            }
        }
    }
    return isRelaxed;
};