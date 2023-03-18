#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, M;
	cin >> L >> M;

	cout << L / M;

	if (L % M == 0) 
		exit(0);
	else {
		cout << '.';
		L -= M * (L / M);
	}

	vector<int> V(M, -1);
	vector<int> R;

	while (true) {
		V[L] = R.size();
		L *= 10;

		int d = L / M;
		L -= M * d;
		R.push_back(d);

		if (L == 0 || V[L] != -1) break;
	}

	for (int i = 0; i < R.size(); i++) {
		if (L != 0 && V[L] == i)
			cout << '(';
		cout << R[i];
	}

	if (L != 0)
		cout << ')';
}