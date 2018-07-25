#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;
#define M 1000000007

int t, k; 
int dp[100001];

int solve() {
    dp[0] = 1;
    for(int i = 1; i <= 1e5; i++) {
        dp[i] = (dp[i-1] + (i >= k ? dp[i-k] : 0)) % M;
    }
}

int main()
{
    cin >> t >> k;
    memset(dp, 0, sizeof dp);
    solve();
    for(int i = 1; i <= 1e5; i++) {
        dp[i] += dp[i-1]%M;
    }
    
    while(t--) {
        int l, r; cin >> l >> r;
        cout << ((dp[r]-dp[l-1])%M+M)%M << endl;
    }
    return 0;
}