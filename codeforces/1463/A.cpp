#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        if((a + b + c) % 9 != 0) {
            cout << "NO\n";
            continue;
        }
        if(min({a, b, c}) >= (a+b+c)/9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}