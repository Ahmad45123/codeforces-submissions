#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll a, b, n, m; cin >> a >> b >> n >> m;
        ll mx = max(a, b);
        ll mn = min(a, b);
        if(n+m > a+b || m > mn) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    
    return 0;
}