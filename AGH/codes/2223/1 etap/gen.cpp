#include <iostream>

using namespace std;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int calculate(int A, int B) {
	int res = 0;
	for (int x = 1 << (A + B - 1); x < (1 << (A + B)); x++)
		if (__builtin_popcount(x) == B && !isPrime(x))
			res++;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;

	cout << calculate(A, B);
}