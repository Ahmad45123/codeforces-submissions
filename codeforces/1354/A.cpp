#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(b >= a)
            cout << b << "\n";
        else {
            if(d >= c)
                cout << -1 << "\n";
            else {
                //ll ans = b;
                ll req = a-b;
                ll diff = c-d;
                ll times = ceil(req*1.0/diff*1.0);
                ll ans = b+c*times;
                cout << ans << "\n";
            }
        }
    }
    
    return 0;
}