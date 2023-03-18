// generating prime numbers up to n
// time complexity: O(n loglog(n)) space: O(n)

vector<ll> P;
vector<bool> IP(n + 1, true);
IP[0] = IP[1] = false;
for (ll i = 2; i < IP.size(); i++) {
	if (IP[i]) {
		P.push_back(i);
		for (ll j = i * i; j < IP.size(); j += i)
			IP[j] = false;
	}
}

// checking whether a number is prime
// time complexity: O(sqrt(n)) space: O(1)

bool isPrime(ll x) {
	if (x <= 1) return false;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

// factorization of a number
// time complexity: O(n) space: O(1)

map<ll, int> Factorize(ll x) {
	map<ll, int> R;
	for (ll i = 2; i < x; i++) {
		while (x % i == 0)
			R[i]++, x /= i;
	}
	return R;
}

// with precomputed prime list
// time complexity: O(p(n)) space: O(1)

map<ll, int> Factorize(ll x) {
	map<ll, int> R;
	for (auto p : P) {
		if (p > x) break;
		while (x % p == 0)
			R[p]++, x /= p;
	}
	return R;
}