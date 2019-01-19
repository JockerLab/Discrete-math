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
 
string s;
int n, cnt_open = 0, cnt_close = 0;
 
void next(int pos = 0) {
    if (pos == -1) {
        cout << "-";
        exit(0);
    }
    if (s[pos] == '(') {
        cnt_open++;
    }
    else {
        cnt_close++;
    }
 
    if (cnt_close > cnt_open && s[pos] == '(') {
        char ch = ')';
        s[pos] = ch;
        return;
    }
    else {
        next(pos - 1);
    }
    char ch = '(';
    if (cnt_open == 0) {
        ch = ')';
        s[pos] = ch;
    }
    else {
        s[pos] = ch;
        cnt_open--;
    }
}
 
int main() {
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> s;
    n = sz(s);
 
    next(sz(s) - 1);
 
    cout << s;
 
    return 0;
}