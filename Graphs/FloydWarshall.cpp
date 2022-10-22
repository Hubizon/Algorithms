// Finds shortest distances between every pair of vertices in a given edge weighted directed Graph
// weights can be negative, but there can be no negative cycles
constexpr int INF = 1e9;
int n; // vertexes
vector<vector<int>> D(n, vector<int>(n, INF));
for (int i = 0; i < n; i++) D[i][i] = 0;

for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = min(D[i][j], D[i][k] + D[k][j]);