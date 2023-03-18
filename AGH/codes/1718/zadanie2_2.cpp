#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
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

	vector<int> F = { 1, 1 };
	while (F.back() < 1e7)
		F.push_back(*F.rbegin() + *++F.rbegin());

	vector<bool> V(1e7);
	for (int i = 0; i < F.size(); i++) {
		int sum = 0;
		for (int j = i; j < F.size(); j++) {
			sum += F[j];
			if (sum >= V.size()) break;
			V[sum] = true;
		}
	}

	for (int i = n + 1; i < V.size(); i++) {
		if (!V[i]) {
			cout << i;
			return 0;
		}
	}
}
