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
 
void gen(vector<int> a, int sum = 0, int k = 1) {
    if (sum >= n) {
        if (sum == n) {
            for (int i = 0; i < sz(a) - 1; i++) {
                cout << a[i] << "+";
            }
 
            cout << a[sz(a) - 1] << endl;
        }
 
        return;
    }
 
    a.push_back(0);
 
    for (int i = k; i <= n; i++) {
        if (i + sum > n) {
            return;
        }
 
        a[sz(a) - 1] = i;
 
        gen(a, sum + i, i);
    }
}
int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<int> a;
 
    gen(a);
 
    return 0;
}