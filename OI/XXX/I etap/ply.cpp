// XXX OI - Płytkie nawiasowanie (Hubert Jastrzębski)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, H;
	string S;
	cin >> n >> H >> S;

	int res = 0;

	for (int i = 0, depth = 0; i < n; i++) {
		depth += (S[i] == '(' ? 1 : -1);
		if (depth < 0)
			depth = 1; // S[i] = '('
		else if (depth > H)
			depth -= 2, res++; // S[i] = ')'
	}

	cout << 2 * res;
}