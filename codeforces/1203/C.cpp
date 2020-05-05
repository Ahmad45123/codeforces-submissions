#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto &x : arr)
        cin >> x;
    
    ll gcd = 0;
    if(n == 1) {
        gcd = arr[0];
    } else {
        gcd = __gcd(arr[0], arr[1]);
        for(int i = 2; i < n; i++)
            gcd = __gcd(gcd, arr[i]);
    }

    ll ans = 0;
    for(ll i = 1; i <= sqrt(gcd); i++) {
        if(gcd % i == 0) {
            ans += (gcd / i == i ? 1 : 2);
        }
    }

    cout << ans << "\n";
    
    return 0;
}