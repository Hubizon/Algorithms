#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	int res = 1;
	for (ll i = 2; i <= n; i++) {
		ll j = i % 10;
		if (j == 0) continue;
		res *= j;
		while (res % 10 == 0)
			res /= 10;
		res %= 10;
	}

	cout << res;
}
