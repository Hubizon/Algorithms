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
	priority_queue<int> Q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}

	while (k--) {
		auto q = Q.top(); Q.pop();
		Q.push(q / 2);
	}

	int res = 0;
	while (Q.size())
		res += Q.top(), Q.pop();

	cout << res;
}
