#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
 
#define sz(s) int(s.size())
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
ll n, k = 0, m;
vector<vector<ll>> d;
 
ll fact(ll a) {
    ll res = 1ll;
 
    for (ll i = 1; i <= a; i++) {
        res *= i;
    }
 
    return res;
}
 
void gen(vector<ll> a, ll p = 0) {
    if (p == k) {
        for (ll i = 0ll; i < k; i++) {
            cout << a[i] << " ";
        }
        exit(0);
    }
 
    ll from = 1ll;
    if (p > 0) {
        from = a[p - 1] + 1;
    }
 
    for (ll i = from; i <= n; i++) {
        ll cnt = d[n - i][k - p - 1ll];
        //ll cnt = fact(n - i) / (fact(k - p - 1) * fact(n - i - k + p + 1));
 
        if (m - cnt >= 0) {
            m -= cnt;
        }
        else {
            a[p] = i;
            gen(a, p + 1ll);
        }
    }
}
 
int main() {
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k >> m;
 
    vector<ll> a(n);
 
    d.resize(100);
 
    for (ll i = 0ll; i < 100; i++) {
        d[i].resize(100);
        d[i][0] = 1ll;
        d[i][i] = 1ll;
    }
 
    for (ll i = 0ll; i < 100; i++) {
        for (ll j = 0ll; j < 100; j++) {
            if (d[i][j] == 0ll && i - 1 >= 0 && j - 1 >= 0) {
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
            }
        }
    }
 
    gen(a);
 
    return 0;
}