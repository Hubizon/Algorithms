// Shortest path from a source vertex to every other in DAG (weights can be negative):
vector<vector<pair<int, int>>> G(n);
int src = 0;

vector<bool> vis(n);
stack<int> R;
function<void(int)> TSort = [&](int u) {
    vis[u] = true;
    for (auto& [v, w] : G[u])
        if (!vis[v])
            TSort(v);
    R.push(u);
};

for (int i = 0; i < n; i++)
    if (!vis[i])
        TSort(i);

vector<int> dist(n, INT32_MAX);
dist[src] = 0;
while (!R.empty()) {
	auto u = R.top(); R.pop();
	if (dist[u] != INT32_MAX) {
		for (auto& [v, w] : G) 
		if (dist[v] > dist[u] + w)
			dist[v] = dist[u] + w;
	}
}