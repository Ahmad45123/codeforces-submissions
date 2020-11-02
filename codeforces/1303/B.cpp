#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, g, b; cin >> n >> g >> b;
        ll neededGood = ceil(n*1.0/2.0);
        if(g >= neededGood)
            cout << n << "\n";
        else {
            cout << max(n, neededGood+(((ll)ceil(neededGood*1.0/g*1.0)-1)*b)) << "\n";
        }
    }
    
    return 0;
}