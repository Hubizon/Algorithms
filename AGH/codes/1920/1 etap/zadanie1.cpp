#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, DL, AL;
	cin >> N >> DL >> AL;

	int res = 0, r = 0;
	for (int i = 0; i < N; i++) {
		if (r > DL) {
			r -= DL, res++;
			continue;
		}
		int t = (DL - r) % AL;
		if (t > 0)
			res++, r = AL - t;
		else r = 0;
	}

	cout << res;
}