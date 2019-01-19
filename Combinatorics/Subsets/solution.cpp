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
 
int n;
 
void gen(vector<int> a, int from = 1) {
    for (int i = 0; i < sz(a); i++) {
        cout << a[i] << " ";
    }
 
    cout << endl;
 
    if (sz(a) == n) {
        return;
    }
 
    a.push_back(0);
 
    for (int i = from; i <= n; i++) {
        a[sz(a) - 1] = i;
 
        gen(a, i + 1);
    }
}
int main() {
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<int> a;
 
    gen(a);
 
    return 0;
}