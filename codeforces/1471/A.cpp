#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n >> x;
        ll mn = 0;
        ll mx = 0;
        for(int i = 0; i < n; i++) {
            int v; cin >> v;
            mx += ceil((v*1.0)/(x*1.0));
            mn += v;
        }
        mn = ceil(mn*1.0/x*1.0);
        cout << mn << " " << mx << "\n";
    }
    
    
    return 0;
}