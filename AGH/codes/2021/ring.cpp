#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int n = S.size();

    vector<int> P;
    for (int i = 2; i < n; i++) {
        bool is_prime = true;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
                is_prime = false;
        if (is_prime)
            P.push_back(i);
    }

    string res = string(n, 'z');

    for (int o = 0; o < n; o++) {
        for (auto& p : P) {
            string temp;
            int pos = o;
            for (int i = 0; i < n; i++) {
                temp += S[pos];
                pos = (pos + p) % n;
            }
            if (temp < res)
                res = temp;
        }
    }

    cout << res;
}
