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
 
void next() {
    vector<int> new_a = a;
    bool flag = false;
 
    for (int i = n - 1; i >= 0; i--) {
        if (new_a[i] == 1) {
            new_a[i] = 0;
        }
        else {
            new_a[i] = 1;
            flag = true;
            break;
        }
    }
 
    if (!flag) {
        cout << "-" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << new_a[i];
        }
        cout << endl;
    }
}
void prev() {
    vector<int> new_a = a;
    bool flag = false;
 
    for (int i = n - 1; i >= 0; i--) {
        if (new_a[i] == 0) {
            new_a[i] = 1;
        }
        else {
            new_a[i] = 0;
            flag = true;
            break;
        }
    }
 
    if (!flag) {
        cout << "-" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << new_a[i];
        }
        cout << endl;
    }
}
 
int main() {
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    char ch;
 
    while (cin >> ch) {
        a.push_back(ch - '0');
        n++;
    }
 
    prev();
    next();
 
    return 0;
}