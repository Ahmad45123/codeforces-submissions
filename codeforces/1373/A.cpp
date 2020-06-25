#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        ll ans1, ans2;
        if(a >= c) {
            ans1 = -1;
        } else {
            ans1 = 1;
        }
        if(a*b <= c) {
            ans2 = -1;
        } else {
            ans2 = b;
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    
    return 0;
}