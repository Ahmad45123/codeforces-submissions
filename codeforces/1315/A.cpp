#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        int ans = y*a;
        ans = max(ans, a*(b-y-1));
        ans = max(ans, x*b);
        ans = max(ans, (a-x-1)*b);
        cout << ans << "\n";
    }
    
    return 0;
}