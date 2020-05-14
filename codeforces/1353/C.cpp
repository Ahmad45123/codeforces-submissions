#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll counter = 1;
        ll ans = 0;
        for(ll i = 3; i <= n; i+=2) {
            ll blocks = i*2+(i-2)*2;
            ans += blocks*counter;
            counter ++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}