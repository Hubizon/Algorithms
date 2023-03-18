#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

/*const int Primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

bool isPrime(long long n) {
    for (auto& a : Primes) {
        if (n == a) return true;
        long long d = 1;
        for (int i = 63; i >= 0; i--) {
            long long x = d;
            d = ((__int128)d * d) % n;
            if (d == 1 && x != 1 && x != n - 1) return false;
            if (((n - 1) >> i) & 1) d = ((__int128)d * a) % n;
        }
        if (d != 1) return false;
    }
    return true;
};

void makeCombiUtil(vector<vector<int>>& ans, vector<int>& tmp, int n, int left, int k)
{
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }

    for (int i = left; i <= n; ++i) {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);

        tmp.pop_back();
    }
}

vector<vector<int>> makeCombi(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    vector<ll> R = { -1, -1, 2, 3, 13, 5, -1, 7, 17, -1, 19, 29, -1, 67, 59,
    -1, 79, 89, -1, 199, 389, -1, 499, 599, -1, 1699, 1889, -1, 1999, 2999,
    -1, 4999, 6899, -1, 25999, 8999, -1, 48889, 56999, -1, 49999, 59999, -1,
    79999, 179999, -1, 199999, 389999, -1, 679999, 599999, -1, 799999, 1799999,
    -1, 4789999, 2999999, -1, 4999999, 7799999, -1, 16999999, 18899999, -1, 19999999,
    29999999, -1, 77899999, 59999999, -1, 268999999, 89999999, -1, 289999999,
    389999999, -1, 778999999, 779999999, -1, 799999999, 2888999999, -1, 12889999999,
    4799999999, -1, 17888899999, 25889999999, -1, 16999999999, 37889999999, -1,
    28999999999, 146999999999, -1, 68899999999, 59999999999, -1, 79999999999,
    269999999999, -1, 488899999999, };
    
    /*for (int k = 1; k < 13; k++) {
        int n = k + 8;
        vector<vector<int>> ans = makeCombi(n, 8);
        for (auto& V : ans) {
            ll x = 0;
            int c = 1, cn = k - 1, C = 0;
            vector<bool> T(n);
            for (auto& v : V) T[v - 1] = 1;
            for (int i = 0; i < n; i++) {
                if (!T[i]) {
                    x += c * pow(10, cn);
                    cn--;
                    C += c;
                }
                else
                    c++;
            }
            if (isPrime(x))
                R[C] = min(R[C], x);
        }
    }*/

    int N;
    cin >> N;
    cout << (R[N] == -1 ? "BRAK" : to_string(R[N]));
}