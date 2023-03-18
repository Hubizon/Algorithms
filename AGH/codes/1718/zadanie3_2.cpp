#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
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

	vector<vector<bool>> V(n, vector<bool>(10));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto c : s)
			V[i][c - '0'] = true;
	}

	int res = 0;
	for (int c = 0; c <= 9; c++) {
		int tr = 0;
		for (int i = 0; i < n; i++) {
			if (V[i][c]) tr++;
			else tr = 0;
			res = max(res, tr);
		}
	}
	cout << res;
}
