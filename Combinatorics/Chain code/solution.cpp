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
 
int cnt(vector<int> a) {
    int res = 0;
 
    for (int i = 0, p = 1; i < sz(a); i++, p *= 2) {
        res += a[i] * p;
    }
 
    return res;
}
 
int main() {
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, p;
 
    cin >> n;
 
    vector<vector<int>> a;
    vector<int> b(n);
    vector<bool> used(1 << n);
 
    a.push_back(b);
    used[cnt(b)] = true;
 
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n - 1; j++) {
            b[j] = b[j + 1];
        }
 
        b[n - 1] = 1;
 
        if (!used[cnt(b)]) {
            a.push_back(b);
            used[cnt(b)] = 1;
        } else {
            b[n - 1] = 0;
 
            if (!used[cnt(b)]) {
                a.push_back(b);
                used[cnt(b)] = 1;
            } else {
                break;
            }
        }
    }
 
    for (int i = 0; i < sz(a); i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
 
        cout << endl;
    }
 
    return 0;
}