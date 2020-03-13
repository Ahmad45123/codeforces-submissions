#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n, h, l, r;
vector<int> arr;
int dp[2001][2001];

int solve(int i, int t) {
    if(i >= n)
        return t >= l && t <= r ? 1 : 0;
    if(dp[i][t] != -1)
        return dp[i][t];
    int ans = 0;
    if(t >= l && t <= r)
        ans ++;
    ans += max(solve(i+1, (t+arr[i])%h), solve(i+1, (t+arr[i]-1)%h));
    dp[i][t] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> h >> l >> r;
    arr = vector<int>(n);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int ans = max(solve(1, arr[0]%h), solve(1, (arr[0]-1)%h));
    
    cout << ans << "\n";

    return 0;
}