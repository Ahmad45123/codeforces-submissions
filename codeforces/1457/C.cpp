#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dp;

ll solve(int i, string &s, int &n, int &k, ll &x) {
    if(i > n)
        return 0;
    if(~dp[i])
        return dp[i];
    return dp[i] = ((s[i-1] == '0' ? x : 0)+solve(i+k, s, n, k, x));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, p, k; cin >> n >> p >> k;
        string s; cin >> s;
        ll x, y; cin >> x >> y;

        dp = vector<ll>(n+1, -1);

        ll ans = 1e18;
        for(int i=p;i<=n;i++){
            ans=min(ans,(i-p)*y+solve(i, s, n, k, x));
        }

        cout << ans << "\n";
    }
    
    return 0;
}