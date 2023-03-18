#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	sort(V.begin(), V.end());

	vector<pair<int, int>> W = { { V[0], 1 } };
	for (int i = 1; i < n; i++) {
		if (V[i] == W.back().first)
			W.back().second++;
		else
			W.push_back({ V[i], 1 });
	}

	int res = 0;
	for (int i = 0; i < W.size(); i++) {
		if ((i != 0 && W[i - 1].first >= W[i].first - k)
			|| (i != W.size() - 1 && W[i + 1].first <= W[i].first + k))
			res += W[i].second;
	}
	cout << res;
}
