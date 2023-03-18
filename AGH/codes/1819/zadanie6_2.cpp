#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int n = S.size();

	string R;
	stack<pair<int, int>> Pos;
	for (int i = 0; i < n; i++) {
		auto s = S[i];
		if (s == '[') 
			Pos.push({ i++, R.size() });
		else if (s == ']') {
			auto pos = Pos.top(); Pos.pop();
			int cnt = S[pos.first + 1] - '0';
			string toR = R.substr(pos.second, R.size() - pos.second);
			while (--cnt)
				R += toR;
		}
		else 
			R += s;
	}

	cout << R;
}
