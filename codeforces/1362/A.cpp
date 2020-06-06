#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool IsPowerOfTwo(ll x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        if(b < a) swap(a, b);
        if(b % a == 0 && IsPowerOfTwo(b/a)) {
            ll twos = log2(b/a);
            ll eights = twos/3;
            twos %= 3;
            ll fours = twos/2;
            twos %= 2;
            cout << eights+fours+twos << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}