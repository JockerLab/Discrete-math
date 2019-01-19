include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
ll n, k;
 
vector<ll> a;
vector< vector<ll> > d;
 
void gen(ll pos = 0ll, ll balance = 0ll) {
    if (pos == 2ll * n) {
        for (ll i = 0ll; i < 2ll * n; i++) {
            if (a[i] == 0ll) {
                cout << "(";
            }
            else {
                cout << ")";
            }
        }
        return;
    }
    ll cnt = d[2ll * n - pos - 1ll][balance + 1ll];
    if (k - cnt < 0ll || (balance == 0ll)) {
        a[pos] = 0ll;
        gen(pos + 1ll, balance + 1ll);
    }
    else {
        k -= cnt;
        a[pos] = 1ll;
        gen(pos + 1ll, balance - 1ll);
    }
}
 
int main() {
    freopen("num2brackets.in", "r", stdin);
    freopen("num2brackets.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
     
    cin >> n >> k;
 
    a.resize(2 * n + 2);
    d.resize(2 * n + 2);
 
    for (int i = 0; i < 2 * n + 1; i++) {
        d[i].resize(2 * n + 2);
    }
 
    d[0][0] = 1;
 
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            d[i][j] += d[i - 1][j + 1];
 
            if (j - 1 >= 0) {
                d[i][j] += d[i - 1][j - 1];
            }
        }
    }
 
    gen();
 
    return 0;
}