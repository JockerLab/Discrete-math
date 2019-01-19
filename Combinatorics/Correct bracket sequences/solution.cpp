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
 
void gen(vector<char> a, int balance = 0) {
    if (sz(a) == 2 * n) {
        if (balance == 0) {
            for (int i = 0; i < 2 * n; i++) {
                cout << a[i];
            }
 
            cout << endl;
        }
        return;
    }
 
    a.push_back('(');
    gen(a, balance + 1);
 
    if (balance - 1 >= 0) {
        a[sz(a) - 1] = ')';
        gen(a, balance - 1);
    }
}
int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    vector<char> a;
 
    gen(a);
 
    return 0;
}