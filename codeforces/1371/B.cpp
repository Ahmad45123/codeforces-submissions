#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, r; cin >> n >> r;
        ll ans = 0;
        if(r >= n) {
            r = n-1;
            ans = 1;
        }
        ans += (r*(r+1))/2;
        cout << ans << "\n";
    }
    
    return 0;
}