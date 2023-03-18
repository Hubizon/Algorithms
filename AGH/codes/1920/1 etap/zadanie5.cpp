#include <iostream>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	int S = 0;
	for (auto& v : V)
		S += v;

	if (n % 2 == 1 || S % 2 == 1) {
		cout << "NIE";
		return 0;
	}
	
	const int W = S / 2 + 10;
	vector<unordered_set<int>> DP(W);
	DP[0].insert(0);
	for (int i = 0; i < n; i++) {
		auto v = V[i];
		for (int w = W - v - 1; w >= 0; w--) {
			for (auto dp : DP[w]) 
				DP[w + v].insert(dp + 1);
		}
	}

	if (DP[S / 2].count(n / 2))
		cout << "TAK";
	else
		cout << "NIE";
}
