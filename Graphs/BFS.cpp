// finding the shorthest path from src (with all weights being 1):
vector<vector<int>> G(n);
vector<int> dist(n, INT32_MAX);
auto distBFS = [&](const int src) {
    dist[src] = 0;
    queue<int> Q; Q.push(src);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        for (auto& v : G[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
};


// finding the shorthest path from src (with weights 0 or 1):
vector<vector<pair<int, bool>>> G(n);
vector<int> dist(n, INT32_MAX);
auto zoBFS = [&](const int src) {
    dist[src] = 0;
    deque<int> Q; Q.push_back(src);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop_front();
        for (auto& [v, w] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) Q.push_front(v);
                else Q.push_back(v);
            }
        }
    }
};

// finding the shortest path from src (weighted tree)
vector<vector<pair<int, int>>> G(n);
vector<int> dist(n);

queue<int> Q; Q.push(i);
while (!Q.empty()) {
	auto u = Q.front(); Q.pop();
	for (auto& [v, w] : G[u]) {
		if (dist[v] != LLONG_MAX) {
		    dist[v] = dist[u] + w;
	 	    Q.push(v);
	    }
	}
}