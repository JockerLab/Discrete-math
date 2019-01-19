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
 
ll n, k = 0;
vector<ll> a;
vector< vector<ll> > d;
 
void gen(ll pos = 0, ll sum = 0, ll k1 = 0) {
    if (sum == 0) {
        cout << k;
        exit(0);
    }
 
    for (int i = k1; i < a[pos]; i++) {
        k += d[sum - i][i];
    }
    gen(pos + 1, sum - a[pos], a[pos]);
}
 
int main() {
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int c, sum = 0;
    char ch;
 
    while (cin >> c) {
        a.push_back(c);
        sum += a[sz(a) - 1];
        cin >> ch;
    }
 
    n = sum;
 
    d.resize(n + 2);
 
    for (int i = 0; i <= n; i++) {
        d[i].resize(n + 2);
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