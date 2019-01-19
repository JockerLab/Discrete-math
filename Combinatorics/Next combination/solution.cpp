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
 
int n, k;
vector<int> a;
 
void next() {
    int j = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] == n - (k - 1 - i) && i == 0) {
            cout << -1;
            exit(0);
        }
        if (a[i] != n - (k - 1 - i)) {
            a[i]++;
            j = i + 1;
            break;
        }
    }
 
    for (; j < k; j++) {
        if (j - 1 >= 0) {
            a[j] = a[j - 1] + 1;
            if (a[j] > n) {
                cout << -1;
                exit(0);
            }
        }
    }
 
    for (int it = 0; it < k; it++) {
        cout << a[it] << " ";
    }
}
 
int main() {
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    a.resize(k);
 
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
 
    next();
 
    return 0;
}