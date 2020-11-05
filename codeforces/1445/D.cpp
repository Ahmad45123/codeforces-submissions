#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 998244353;

const ll N = 2*150007;
ll fact[N];
 
ll fast_mod_exp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
 
        a = (a * a) % m;
        b = b >> 1;
    }
 
    return res;
}
 
ll mod_inverse(ll a, ll m)
{
    return fast_mod_exp(a, m - 2, m);
}
 
void precompute()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

ll ncr(ll n, ll r, ll p)
{
    precompute();
    if (r == 0)
        return 1;
 
    return ((fact[n] * mod_inverse(fact[n - r], p)) % p * mod_inverse(fact[r], p)) % p;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    

    int n; cin >> n;
    vector<int> arr(2*n);
    for(int &x : arr)
        cin >> x;

    sort(arr.begin(), arr.begin()+n);
    sort(arr.begin()+n, arr.end(), greater<int>());
    
    ll value = 0;
    for(int i = 0; i < n; i++) {
        value += abs(arr[i]-arr[n+i]);
    }
    value %= M;
    value *= ncr(2*n, n, M)%M;
    value %= M;

    cout << value << "\n";

    return 0;
}