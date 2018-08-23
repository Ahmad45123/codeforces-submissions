#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while(k--) {
        ll fa, ta, fb, tb; cin >> ta >> fa >> tb >> fb;
        ll ans = 0;
        if(ta != tb && (fa < a || fa > b)) { //if not same tower, get to nearest floor with ways.
            if(abs(fa-a) <= abs(fa-b)) {
                ans += abs(fa-a);
                fa = a;
            }
            else {
                ans += abs(fa-b);
                fa = b;
            }
        }

        ans += abs(ta-tb);
        ans += abs(fa-fb);
        cout << ans << endl;
    }
    return 0;
}