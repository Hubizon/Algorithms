#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

constexpr int INF = 1e9;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	auto s = max_element(S.begin(), S.end());
	while (s != S.end()) {
		cout << *s;
		s = max_element(s + 1, S.end());
	}
}
