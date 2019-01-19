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
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int n;
 
    cin >> n;
 
    for (int i = 0; i < (1 << n); i++) {
        vector<int> a(n);
 
        int j = i, cnt = 0;
 
        while (j > 0) {
            a[cnt++] = j % 2;
            j /= 2;
        }
 
        reverse(a.begin(), a.end());
 
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
 
        cout << endl;
    }
 
    return 0;
}