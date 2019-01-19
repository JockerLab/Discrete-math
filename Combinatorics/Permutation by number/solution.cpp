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
 
ll n, k;
 
ll fact(ll a) {
    ll res = 1ll;
 
    for (ll i = 1; i <= a; i++) {
        res *= i;
    }
 
    return res;
}
 
void gen(vector<ll> a, ll p = 0) {
    if (p == n) {
        for (ll i = 0ll; i < n; i++) {
            cout << a[i] << " ";
        }
        exit(0);
    }
 
    for (ll i = 1ll; i <= n; i++) {
        int flag = 0;
 
        for (ll j = 0ll; j < p; j++) {
            if (a[j] == i) {
                flag = 1;
                break;
            }
        }
 
        if (flag == 0) {
            ll cnt = fact(n - p - 1ll);
            if (k - cnt >= 0) {
                k -= cnt;
            }
            else {
                a[p] = i;
 
                gen(a, p + 1ll);
            }
        }
    }
}
int main() {
    freopen("num2perm.in", "r", stdin);
    freopen("num2perm.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    vector<ll> a(n);
 
    gen(a);
 
    return 0;
}