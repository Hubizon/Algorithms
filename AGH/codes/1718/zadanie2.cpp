#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> Fib = { 1, 1 };
    while (Fib.back() < 1e6)
        Fib.push_back(*Fib.rbegin() + *++Fib.rbegin());

    vector<bool> V(1e7);
    for (int i = 0; i < Fib.size(); i++) {
        ll x = 0;
        for (int j = i; j < Fib.size(); j++) {
            x += Fib[j];
            V[x] = true;
        }
    }

    for (int i = n + 1; i < V.size(); i++) {
        if (!V[i]) {
            cout << i;
            exit(0);
        }
    }
}


int main()
{
    solve();
}
