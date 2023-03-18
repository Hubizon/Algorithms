#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <array>
#include <cmath>
#include <set>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> V(n);
	for (auto& v : V)
		cin >> v;

	vector<ll> S;
	for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
		ll sum = 0;
		for (int i = 0; i < n; i++)
			if ((bitmask >> i) & 1)
				sum += V[i];
		S.push_back(sum);
	}

	sort(S.begin(), S.end());
	S.resize(unique(S.begin(), S.end()) - S.begin());
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i + 1] != S[i] + 1) {
			cout << S[i] + 1;
			return 0;
		}
	}

	cout << S.back() + 1;
}
