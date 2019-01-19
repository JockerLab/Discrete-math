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
 
int n;
 
vector<vector<int>> ans;
 
void gen(vector<int> a) {
    if (sz(a) == n) {
        ans.push_back(a);
 
        return;
    }
 
    a.push_back(0);
 
    if (sz(a) == 1) {
        gen(a);
        a[0] = 1;
        gen(a);
    } else {
        gen(a);
 
        if (a[sz(a) - 2] == 0) {
            a[sz(a) - 1] = 1;
            gen(a);
        }
    }
}
int main() {
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<int> a;
 
    gen(a);
 
    cout << sz(ans) << endl;
 
    for (int j = 0; j < sz(ans); j++, cout << endl) {
        for (int i = 0; i < n; i++) {
            cout << ans[j][i];
        }
    }
 
    return 0;
}