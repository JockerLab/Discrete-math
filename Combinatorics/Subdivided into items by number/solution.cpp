#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
ll n, k;
 
vector<ll> a;
vector< vector<ll> > d;
 
void gen(ll pos = 0, ll sum = 0, ll k1 = 0) {
    if (sum == 0) {
        for (int i = 0; i < sz(a) - 1; i++) {
            cout << a[i] << "+";
        }
        cout << a[sz(a) - 1];
        exit(0);
    }
 
    for (int i = k1; i <= n; i++) {
        if (sum - i >= 0) {
            ll cnt = d[sum - i][i];
            if (cnt <= k) {
                k -= cnt;
            }
            else {
                a.push_back(i);
                gen(pos + 1, sum - i, i);
            }
        }
    }
}
 
int main() {
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    d.resize(n + 2);
    for (int i = 0; i <= n; i++) {
        d[i].resize(n + 1);
    }
 
    for (int i = 0; i <= n; i++) {
        d[0][i] = 1;
    }
 
    for (int i = 0; i <= n; i++) {
        for (int j = n; j > 0; j--) {
            if (i == n && j == n) {
                int kek = 0;
            }
            if (i > j && j + 1 <= n) {
                d[i][j] = d[i - j][j] + d[i][j + 1];
            }
            if (i == j) {
                d[i][j] = 1;
            }
        }
    }
 
    gen(0ll, n, 1ll);
 
    return 0;
}