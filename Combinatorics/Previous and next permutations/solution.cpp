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
 
int n = 0;
 
vector<int> a;
 
bool cmp(int a, int b) {
    return a > b;
}
 
void next() {
    int flag = 0;
    vector<int> b;
    b.push_back(a[n - 1]);
 
    for (int i = n - 2; i >= 0; i--) {
        b.push_back(a[i]);
        if (a[i] < a[i + 1]) {
            flag = i + 1;
            break;
        }
    }
 
    if (flag > 0) {
        int _min = n;
        flag--;
 
        sort(b.begin(), b.end());
 
        for (int i = 0; i < sz(b); i++) {
            if (b[i] > a[flag]) {
                _min = b[i];
                break;
            }
        }
 
        a[flag] = _min;
 
        for (int i = flag + 1, j = 0; i < n; i++, j++) {
            if (b[j] != _min) {
                a[i] = b[j];
            }
            else {
                a[i] = b[++j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
 
        cout << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    }
}
void prev() {
    int flag = 0;
    vector<int> b;
    b.push_back(a[n - 1]);
 
    for (int i = n - 2; i >= 0; i--) {
        b.push_back(a[i]);
        if (a[i] > a[i + 1]) {
            flag = i + 1;
            break;
        }
    }
 
    if (flag > 0) {
        int _min = n;
        flag--;
 
        sort(b.begin(), b.end());
 
        for (int i = 0; i < sz(b); i++) {
            if (b[i] < a[flag]) {
                _min = b[i];
            }
        }
 
        a[flag] = _min;
 
        for (int i = flag + 1, j = sz(b) - 1; i < n; i++, j--) {
            if (b[j] != _min) {
                a[i] = b[j];
            }
            else {
                a[i] = b[--j];
            }
        }
 
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
 
        cout << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    }
}
int main() {
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    a.resize(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    if (n == 1) {
        cout << 0 << endl << 0;
        return 0;
    }
 
    vector<int> a1 = a;
 
    prev();
 
    a = a1;
 
    next();
 
    return 0;
}