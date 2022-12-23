// returns a^k % q (you can also exponentiate e.g. matrices)
// time complexity: O(log(n)), space: O(1)

typedef long long ll;

ll quickPower(ll a, int k, int q) {
    ll out = 1;
    while (k) {
        if (k & 1) (out *= a) %= q;
        k >>= 1;
        (a *= a) %= q;
    }
    return out;
};