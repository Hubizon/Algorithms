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

    vector<array<bool, 10>> V(n);
    for (auto& v : V) {
        int x;
        cin >> x;
        for (int i = 0; i <= 9; i++)
            v[i] = false;
        string s = to_string(x);
        for (auto c : s)
            v[c - '0'] = true;
    }

    int res = 0;
    for (int i = 0; i <= 9; i++) {
        int tr = 0;
        for (auto& v : V) {
            if (v[i])
                tr++;
            else {
                res = max(res, tr);
                tr = 0;
            }
        }
    }

    cout << res;
}


int main()
{
    solve();
}
