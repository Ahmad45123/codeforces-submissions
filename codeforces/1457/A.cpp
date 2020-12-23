#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, m, r, c; cin >> n >> m >> r >> c;
        ll ans = 0;
        ans = max(ans, abs(1 - r) + abs(1 - c));
        ans = max(ans, abs(n - r) + abs(m - c));
        ans = max(ans, abs(1 - r) + abs(m - c));
        ans = max(ans, abs(n - r) + abs(1 - c));
        cout << ans << "\n";
    }
    
    return 0;
}