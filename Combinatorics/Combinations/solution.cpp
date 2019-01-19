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
 
int n, k;
 
void gen(vector<int> a) {
    if (sz(a) == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
 
        cout << endl;
 
        return;
    }
 
    a.push_back(0);
 
    int to = 1;
 
    if (sz(a) > 1) {
        to = a[sz(a) - 2] + 1;
    }
 
    for (int i = to; i <= n; i++) {
        a[sz(a) - 1] = i;
        gen(a);
    }
}
int main() {
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    vector<int> a;
 
    gen(a);
 
    return 0;
}