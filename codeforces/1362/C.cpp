#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> getValue(ll n) {
    ll prev = 0;
    ll tmp = 1;
    ll cur = 1;
    ll ans = 0;
    while(cur <= n) {
        ans += prev;
        prev = ans;
        ans += tmp;
        tmp ++;
        cur *= 2;
    }
    cur /= 2;
    return {ans, cur};
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll ans = 0;

        do {
            pair<ll, ll> cur = getValue(n);
            ans += cur.first;
            n -= cur.second;
        }
        while(n != 0);

        cout << ans << "\n";
    }
    
    return 0;
}