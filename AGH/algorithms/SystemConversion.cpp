// Convert a number from one system into another

// any base -> decimal
int base;
string S;
ll x = stoll(S, nullptr, base);

// alternatively
ll anyToDecimal(string S, int base) {
	ll x = 0, p = 1;
	for (int i = S.size() - 1; i >= 0; i--, p *= base) {
		if (S[i] >= 'A') 
			x += (S[i] - 'A' + 10) * p;
		else 
			x += (S[i] - '0') * p;
	}
	return x;
}

// decimal -> binary
string decimalToBinary(ll x) {
	string S;
	while (x) {
		S += x % 2 + '0';
		x /= 2;
	}
	return string(S.rbegin(), S.rend());
}

// decimal -> any base
string decimalToAny(ll x, int base) {
	string S;
	while (x) {
		if (x % base >= 10)
			S += x % base - 10 + 'A';
		else
			S += x % base + '0';
		x /= base;
	}
	return string(S.rbegin(), S.rend());
}
