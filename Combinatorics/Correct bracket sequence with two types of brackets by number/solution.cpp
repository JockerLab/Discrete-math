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
 
vector<char> a;
vector< vector<ll> > d;
 
void gen(stack<char> st, ll pos = 0ll, ll balance = 0ll) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        exit(0);
    }
 
    if (k < d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll))) {
        a[pos] = '(';
        st.push('(');
        gen(st, pos + 1ll, balance + 1ll);
    }
    else {
        if (k - d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll)) >= 0) {
            k -= d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll));
        }
 
        if (balance > 0 && k < d[n - pos - 1ll][balance - 1ll] * (1ll << ((n - pos - balance) / 2ll)) && !st.empty() && st.top() == '(') {
            a[pos] = ')';
            st.pop();
            gen(st, pos + 1ll, balance - 1ll);
        }
        else {
            if (!st.empty() && st.top() == '(' && balance > 0ll && k - d[n - pos - 1ll][balance - 1ll] * (1ll << ((n - pos - balance) / 2ll)) >= 0) {
                k -= d[n - pos - 1ll][balance - 1ll] * (1ll << ((n - pos - balance) / 2ll));
            }
 
            if (k < d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll))) {
                a[pos] = '[';
                st.push('[');
                gen(st, pos + 1ll, balance + 1ll);
            }
            else {
                if (!st.empty() && st.top() == '[' && k - d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll)) >= 0) {
                    k -= d[n - pos - 1ll][balance + 1ll] * (1ll << ((n - pos - balance - 2ll) / 2ll));
                }
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                a[pos] = ']';
                gen(st, pos + 1ll, balance - 1ll);
            }
        }
    }
}
 
int main() {
    freopen("num2brackets2.in", "r", stdin);
    freopen("num2brackets2.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n >> k;
 
    n *= 2ll;
 
    a.resize(n + 2ll);
    d.resize(n + 2ll);
 
    for (int i = 0; i < n + 1ll; i++) {
        d[i].resize(n + 2ll);
    }
 
    d[0][0] = 1ll;
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] += d[i - 1][j + 1];
 
            if (j - 1 >= 0ll) {
                d[i][j] += d[i - 1][j - 1];
            }
        }
    }
 
    stack<char> st;
 
    gen(st);
 
    return 0;
}