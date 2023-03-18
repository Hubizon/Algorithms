#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> V(n);
    for (auto& v : V)
        cin >> v;

    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        ll tres = 0;
        for (int i = 0; i < n; i++)
            if ((bitmask >> i) & 1)
                tres += V[i];
        V.push_back(tres);
    }
    
    sort(V.begin(), V.end());

    ll res = V.back() + 1;
    for (int i = 1; i < V.size(); i++) {
        if (V[i] - V[i - 1] > 1) {
            res = V[i - 1] + 1;
            break;
        }
    }

    cout << res;
}

int main()
{
    solve();
}

