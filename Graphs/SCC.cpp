// strongly connected components in a directed graph (Tarjan's algorithm):
int n;
vector<vector<int>> G(n);

int cnt = 0, sccCnt = 1;
stack<int> S;
vector<int> SCC(n);
vector<int> tin(n, -1), low(n, -1);
function<void(int)> DFS = [&](int u) {
    tin[u] = low[u] = cnt++;
    S.push(u);
    for (auto& v : G[u]) {
        if (tin[v] == -1) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if (tin[v] != INT32_MAX)
            low[u] = min(low[u], tin[v]);
    }

    if (low[u] == tin[u]) {
        int v;
        do {
            v = S.top(); S.pop();
            SCC[v] = sccCnt;
            tin[v] = INT32_MAX;
        } while (u != v);
        sccCnt++;
    }
};

for (int u = 0; u < n; u++) {
    if (tin[u] == -1)
        DFS(u);
}


// strongly connected components in a directed graph (Kosaraju's algorithm):
vector<vector<int>> G(n), RG(n);
vector<bool> visited(n);
stack<int> S;

function<void(int)> FOrder = [&](int u) {
    if (visited[u]) return;
	visited[u] = true;
    for (auto v : G[u])
        FOrder(v);
    S.push(u);
};

for (int i = 0; i < n; i++)
    FOrder(i);

// not needed if you already have a reversed graph:
for (int i = 0; i < n; i++) //
    for (auto& g : G[i]) //
        RG[g].push_back(i); //

int scccnt = 1;
vector<int> SCC(n); // wynik - tablica z numerem scc dla każdego wierzchołka
function<void(int)> rDFS = [&](int u) {
    if (SCC[u]) return;
    SCC[u] = scccnt;
	for (auto& v : RG[u])
		rDFS(v);
};

while (!S.empty()) {
    if (!SCC[S.top()]) {
        rDFS(S.top());
        scccnt++;
    }
    S.pop();
}