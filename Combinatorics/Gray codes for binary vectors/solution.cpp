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
 
int main() {
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    vector< vector<int> > a;
    vector<int> b(1, 0);
 
    a.push_back(b);
    a.push_back(b);
    a[1][0] = 1;
 
    while (a.size() < (1 << n)) {
        int j = sz(a);
 
        for (int i = j - 1; i >= 0; i--) {
            a.push_back(a[i]);
            a[i].push_back(0);
        }
        for (int i = j; i < sz(a); i++) {
            a[i].push_back(1);
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