#include <iostream>
#include <vector>
#include <string>

using namespace std;

constexpr int MINF = -1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> R(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '#')
				R[j][i] = MINF;
		}
	}

	for (int j = 1; j < n; j++)
		if (R[0][j] != MINF)
			R[0][j] = R[0][j - 1] + 1;

	for (int i = 1; i < n; i++) {
		vector<int> A(n, MINF), B(n, MINF);

		if (R[i][0] != MINF)
			A[0] = R[i - 1][0] + 1;

		for (int j = 1; j < n; j++)
			if (R[i][j] != MINF)
				A[j] = max(R[i - 1][j], A[j - 1]) + 1;

		if (R[i][n - 1] != MINF)
			B[n - 1] = R[i - 1][n - 1] + 1;

		for (int j = n - 2; j >= 0; j--)
			if (R[i][j] != MINF)
				B[j] = max(R[i - 1][j], B[j + 1]) + 1;

		for (int j = 0; j < n; j++)
			R[i][j] = max(A[j], B[j]);
	}

	cout << (R[n - 1][n - 1] < 0 ? "BRAK" : to_string(R[n - 1][n - 1]));
}