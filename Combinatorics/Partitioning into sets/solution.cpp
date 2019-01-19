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
 
void gen(vector<vector<int>> a, int last = 1) {
    if (last == n + 1) {
        int flag = 0;
 
        for (int i = 0; i < k; i++) {
            if (sz(a[i]) == 0) {
                flag = 1;
                break;
            }
        }
 
        if (flag == 1) {
            return;
        }
 
        for (int i = 0; i < k; i++, cout << endl) {
            for (int j = 0; j < sz(a[i]); j++) {
                cout << a[i][j] << " ";
            }
        }
 
        cout << endl;
 
        return;
    }
 
    for (int i = 0; i < k; i++) {
        if (sz(a[i]) == 0) {
            if (i == 0 || (sz(a[i - 1]) > 0 && a[i - 1][0] < last)) {
                vector<vector<int>> b = a;
 
                b[i].push_back(last);
                gen(b, last + 1);
            } else {
                return;
            }
        } else {
            vector<vector<int>> b = a;
 
            b[i].push_back(last);
            gen(b, last + 1);
        }
    }
}
int main() {
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    vector<vector<int>> a(k);
 
    gen(a);
 
    return 0;
}