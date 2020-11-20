#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
}

ll modInverse(ll a, ll m) 
{ 
    ll g = __gcd(a, m); 
    if (g != 1) 
        return -1;
    else 
    { 
        return power(a, m - 2, m); 
    } 
} 

#define M 998244353

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n; cin >> n;

    ll ans = 1;
    int prev = 1, prevPrev = 1;
    for(int i = 3; i <= n; i ++) {
        prevPrev = prev;
        prev = ans;
        ans = prev + prevPrev;
        ans %= M;
    }

    ll invrse = modInverse(power(2, n, M), M);

    cout << (ans*invrse)%M << "\n";

    return 0;
}