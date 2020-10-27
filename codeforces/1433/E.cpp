#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n; cin >> n;

    ll ans = 1;
    for(int i = n-1; i >= 1; i--)
        ans *= i;
    ans /= (n/2);

    cout << ans << "\n";
    
    return 0;
}