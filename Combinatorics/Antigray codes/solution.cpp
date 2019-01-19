#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
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
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n, p;
 
    cin >> n;
 
    p = _pow(3, n);
 
    vector< vector<int> > b(p / 3), a;
 
    for (int i = 0; i < p / 3; i++) {
        int j = i;
 
        while (j > 0) {
            b[i].push_back(j % 3);
            j /= 3;
        }
 
        while (b[i].size() < n) {
            b[i].push_back(0);
        }
    }
 
    int cnt = 0;
 
    while (sz(a) < p) {
        vector<int> a1 = b[cnt];
        a.push_back(b[cnt++]);
 
        int j = 0;
 
        while (j < 2) {
            for (int i = 0; i < n; i++) {
                a1[i]++;
                a1[i] %= 3;
            }
 
            a.push_back(a1);
 
            j++;
        }
    }
 
    for (int i = 0; i < p; i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << a[i][j];
        }
         
        cout << endl;
    }
 
    return 0;
}