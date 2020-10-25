#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

vector<int> dp;

int solve(int i, int &n, vector<int> &arr) {
    if(i > n)
        return 0;
    if(~dp[i])
        return dp[i];
    dp[i] = 1;
    for(int j = 2*i; j <= n; j += i) {
        if(arr[j-1] > arr[i-1])
            dp[i] = max(dp[i], 1+solve(j, n, arr));
    }
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        dp.assign(n+1, -1);

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, solve(i, n, arr));

        cout << ans << "\n";
    }
    
    return 0;
}