#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <array>

using namespace std;

typedef long long ll;

bool isPrime(ll x) {
	if (x <= 1)
		return false;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	int res = 0;
	function<void(ll, ll)> fun = [&](ll x, ll ten) {
		if (x != 0) {
			if (x >= n || !isPrime(x))
				return;
			res++;
		}
		for (int i = 1; i <= 9; i += 2) {
			ll tx = ten * i + 10 * x + i;
			fun(tx, ten * 100);
		}
	};

	fun(0, 10);
	for (int i = 2; i <= 9; i++)
		fun(i, 100);

	cout << res;
}
