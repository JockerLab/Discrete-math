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
 
ll n, k = 0;
 
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
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<ll> a(n), e(n), used(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
 
        e[i] = i + 1;
    }
 
    for (int i = 0; i < n; i++) {
        ll cnt = 0ll;
 
        for (int j = 0; j < n; j++) {
            if (e[j] == a[i]) {
                break;
            }
 
            if (!used[e[j] - 1]) {
                cnt++;
            }
        }
 
        used[a[i] - 1] = 1ll;
 
        k += cnt * fact(n - i - 1);
    }
 
    cout << k;
 
    return 0;
}