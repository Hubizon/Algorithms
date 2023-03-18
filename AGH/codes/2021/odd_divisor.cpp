#include <iostream>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int t = i;
		while (t % 2 == 0)
			t /= 2;
		res += t;
	}

	cout << res;
}
