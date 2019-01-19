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
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
 
        cout << endl;
 
        return;
    }
 
    a.push_back(0);
 
    for (int i = 1; i <= n; i++) {
        int flag = 0;
 
        for (int j = 0; j < sz(a) - 1; j++) {
            if (a[j] == i) {
                flag = 1;
                break;
            }
        }
 
        if (flag == 0) {
            a[sz(a) - 1] = i;
            gen(a);
        }
    }
}
int main() {
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<int> a;
 
    gen(a);
 
    return 0;
}