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
 
ll n, k;
 
string s;
vector< vector<ll> > d;
 
void gen(stack<char> st, ll pos = 0ll, ll balance = 0ll) {
    if (pos == n) {
        cout << k;
        exit(0);
    }
 
    int b1 = balance;
 
    if (s[pos] == '(') {
        st.push('(');
        gen(st, pos + 1, balance + 1);
    }
    if (s[pos] == ')') {
        k += d[n - pos - 1][balance + 1] * (1 << ((n - pos - balance - 2) / 2));
 
        if (st.top() == '(') {
            st.pop();
        }
 
        gen(st, pos + 1, balance - 1);
    }
    if (s[pos] == '[') {
        k += d[n - pos - 1][balance + 1] * (1 << ((n - pos - balance - 2) / 2));
        if (balance > 0 && st.top() == '(') {
            k += d[n - pos - 1][balance - 1] * (1 << ((n - pos - balance) / 2));
        }
        st.push('[');
        gen(st, pos + 1, balance + 1);
    }
    if (s[pos] == ']') {
        k += d[n - pos - 1][balance + 1] * (1 << ((n - pos - balance - 2) / 2)) * 2;
        if (balance > 0 && st.top() == '(') {
            k += d[n - pos - 1][balance - 1] * (1 << ((n - pos - balance) / 2));
        }
        if (st.top() == '[') {
            st.pop();
        }
        gen(st, pos + 1, balance - 1);
    }
}
 
int main() {
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> s;
    n = sz(s);
 
    d.resize(n + 2);
 
    for (int i = 0; i < n + 1; i++) {
        d[i].resize(n + 2);
    }
 
    d[0][0] = 1;
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] += d[i - 1][j + 1];
 
            if (j - 1 >= 0) {
                d[i][j] += d[i - 1][j - 1];
            }
        }
    }
 
    stack<char> st;
 
    gen(st);
 
    return 0;
}