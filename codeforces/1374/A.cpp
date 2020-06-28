#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll x, y, n; cin >> x >> y >> n;
        ll rem = n%x;
        if(rem == y) {
            cout << n << "\n";
        } else if(rem > y) {
            cout << n-(rem-y) << "\n";
        } else {
            n -= rem;
            n -= (x-y);
            cout << n << "\n";
        }
    }
    
    return 0;
}