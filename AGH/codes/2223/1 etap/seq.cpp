#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<ll, ll>> V(n);
	for (auto& v : V)
		cin >> v.first >> v.second;

	vector<pair<ll, ll>> Q(n);
	for (int i = 0; i < n - 1; i++) {
		ll a = V[i].first * V[i + 1].second;
		ll b = V[i].second * V[i + 1].first;
		ll g = gcd(a, b);
		a /= g, b /= g;
		Q[i] = { a, b };
	}

	Q.push_back({ -1, 1 });

	int res = 0;
	pair<ll, ll> prev = Q.front();
	for (int i = 1, cnt = 0; i < n; i++) {
		if (Q[i] == prev) 
			cnt++;
		else 
			prev = Q[i], res = max(res, cnt), cnt = 0;
	}

	cout << (res > 0 ? to_string(res + 2) : "BRAK");
}