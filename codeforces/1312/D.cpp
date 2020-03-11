#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define M 998244353

ll facts[2*100000+1] = {};

int mul(int x, int y)
{
    return (x * 1ll * y) % M;
}
int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
int inv(int x)
{
    return binpow(x, M - 2);
}
int divide(int x, int y)
{
    return mul(x, inv(y));
}

void precompute() {
    facts[0] = 1;
    for(int i = 1; i <= 2*100000; i++) {
        facts[i] = (facts[i-1]*i%M)%M;
    }
}

ll combinatric(ll a, ll b) {
    ll multip = mul(facts[b], facts[a-b]);
    ll t = mul(facts[a], inv(multip));
    return t;
}

int main()
{
    precompute();

    int n, m; cin >> n >> m;
    ll ans = 0;
    if(n > 2)
        ans = mul(mul(binpow(2, n-3), (combinatric(m, n-1)%M)), (n-2)%M);
    cout << ans << "\n";
    
    return 0;
}