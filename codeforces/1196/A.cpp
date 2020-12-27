#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << (a+b+c)/2LL << "\n";
    }
    
    return 0;
}