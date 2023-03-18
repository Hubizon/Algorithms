#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string decToBin(ll n) {
    string res;
    while (n) {
        res += ('0' + n % 2);
        n /= 2;
    }
    return string(res.rbegin(), res.rend());
}

void solve() {
    ll n, k;
    cin >> n >> k;

    string ns = decToBin(n);
    if (k >= ns.size())
        cout << stoll(string(k, '1'), nullptr, 2);
    else if (ns.find(string(k, '1')) != string::npos)
        cout << n;
    else {
        vector<ll> V;
        for (int i = 0; i <= ns.size() - k; i++) {
            string t = ns.substr(0, i) + string(k, '1') + string(ns.size() - k - i, '0');
            V.push_back(stoll(t, nullptr, 2));
        }
        cout << *min_element(V.begin(), V.end());
    }
}

int main()
{
    solve();
}