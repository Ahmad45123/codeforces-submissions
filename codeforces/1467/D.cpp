#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef long long ll;

int n, k, q;
vector<vector<ll>> dp;

int fill(int i, int rem) {
    if(i < 0 || i >= n) return 0;
    if(~dp[i][rem]) { 
        return dp[i][rem];
    }
    if(rem == 0) {
        return dp[i][rem] = 1;
    }
    int toAdd = (fill(i-1, rem-1)%M + fill(i+1, rem-1)%M)%M;
    return dp[i][rem] = toAdd;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> k >> q;
    dp = vector<vector<ll>>(n, vector<ll>(k+1, -1));
    vector<ll> freqs(n, 0);
    for(int i = 0; i < n; i++)
        fill(i, k);

    for(int i = 0; i < n; i++) {
        ll sum = 0;
        for(int j = 0; j <= k; j++) {
            sum += ((dp[i][j]%M)*(dp[i][k-j]%M))%M;
            sum %= M;
        }
        freqs[i] = sum%M;
    }

    vector<ll> arr(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i] %= M;
        ans += (freqs[i]*arr[i])%M;
        ans %= M;
    }
    
    while(q--) {
        int i, x; cin >> i >> x; i--;
        ans -= (arr[i]*freqs[i])%M;
        arr[i] = x;
        ans += (arr[i]*freqs[i])%M + M;
        ans %= M;
        cout << ans << "\n";
    }

    return 0;
}