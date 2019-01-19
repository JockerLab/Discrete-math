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
 
int _pow(int a, int b) {
    int res = a;
 
    while (b > 1) {
        res *= a;
        b--;
    }
 
    return res;
}
 
int main() {
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, k, p;
 
    cin >> n >> k;
 
    p = _pow(k, n);
 
    vector< vector<int> > a;
    vector<int> b(1, 0);
 
    for (int i = 0; i < k; i++) {
        a.push_back(b);
        b[0] = i + 1;
    }
 
    while (sz(a) < p) {
        int j = sz(a);
 
        for (int i = 1, q = 0; i < k; i++, q ^= 1) {
            if (q == 0) {
                for (int z = j - 1; z >= 0; z--) {
                    a.push_back(a[z]);
                    a[sz(a) - 1].push_back(i);
                }
            } else {
                for (int z = 0; z < j; z++) {
                    a.push_back(a[z]);
                    a[sz(a) - 1].push_back(i);
                }
            }
        }
 
        for (int i = 0; i < sz(a) / k; i++) {
            a[i].push_back(0);
        }
    }
 
    for (int i = 0; i < sz(a); i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << a[i][j];
        }
 
        cout << endl;
    }
 
    return 0;
}