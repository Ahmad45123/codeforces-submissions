#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    int t; cin >> t;
    ll ans = 0;
    while(t--) {
        ll a, b; cin >> a >> b;
        ll i = -1;
        ll j = -1;
        if(a != 0) {
            if(a > 0) {
                i = ceil((n-x)*1.0/a);
                while(x+i*a > n)
                    i--;
            } else {
                i = ceil((1-x)*1.0/a);
                while(x+i*a < 1)
                    i--;
            }
        }
        if(b != 0) {
            if(b > 0) {
                j = ceil((m-y)*1.0/b);
                while(y+j*b > m)
                    j--;
            } else {
                j = ceil((1-y)*1.0/b);
                while(y+j*b < 1)
                    j--;
            }
        }
        ll k = i == -1 ? j : j == -1 ? i : min(i, j);
        x += k*a;
        y += k*b;
        ans += k;
    }
    cout << ans << "\n";
    return 0;
}