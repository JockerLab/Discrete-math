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
 
int n, steps = 0;
vector<int> a;
 
void next(int pos = 0, int k = 0) {
    if (pos == 0) {
        if (a[pos] == n && steps != 0) {
            cout << n << "=" << n;
            exit(0);
        }
        cout << "No solution";
        exit(0);
    }
    steps++;
    a[pos]--;
    a[pos - 1]++;
    if (a[pos - 1] <= a[pos] && a[pos] < a[pos - 1] * 2) {
        cout << n << "=";
        for (int i = 0; i < pos; i++) {
            cout << a[i] << "+";
        }
        cout << a[pos];
        exit(0);
    }
    if (a[pos] >= a[pos - 1] * 2) {
        for (int i = pos; a[i] >= a[i - 1] * 2; i++, pos++) {
            a[i + 1] = a[i] - a[i - 1];
            a[i] = a[i - 1];
        }
        cout << n << "=";
        for (int i = 0; i < pos; i++) {
            cout << a[i] << "+";
        }
        cout << a[pos];
        exit(0);
    }
    /*if (a[pos - 1] + 1 <= a[pos] - 1) {
        a[pos - 1]++;
        a[pos]--;
        cout << n << "=";
        for (int i = 0; i < pos; i++) {
            cout << a[i] << "+";
        }
        cout << a[pos];
        exit(0);
    }*/
    else {
        int last = a[pos - 1];
        a[pos - 1] += a[pos];
        if (pos == 1 || ((pos - 2 >= 0) && a[pos - 2] <= a[pos - 1])) {
            cout << n << "=";
            for (int i = 0; i < pos - 1; i++) {
                cout << a[i] << "+";
            }
            cout << a[pos - 1];
            exit(0);
        }
        next(pos - 1, last);
    }
}
 
int main() {
    freopen("nextpartition.in", "r", stdin);
    freopen("nextpartition.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    char ch;
    int b;
 
    cin >> n >> ch;
 
    while (cin >> b) {
        cin >> ch;
        a.push_back(b);
    }
 
    int _sz = sz(a);
 
    a.resize(100010);
 
    next(_sz - 1, 0);
 
    return 0;
}