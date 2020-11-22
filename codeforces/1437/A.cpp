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
        int l, r; cin >> l >> r;
        if((r+1)*1.0/2.0 <= l)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}