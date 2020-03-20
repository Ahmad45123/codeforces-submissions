#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n; 
vector<pair<int, int>> arr;

int dp[100001][2];

int solve(int i, int canDropBefore) {
    if(i == n-1)
        return 0;

    if(dp[i][canDropBefore] != -1)
        return dp[i][canDropBefore];
    
    bool can = (arr[i+1].first - arr[i].first - 1) >= arr[i+1].second;
    int ans = solve(i+1, can);

    if(canDropBefore) {
        ans ++;
    }
    
    if(arr[i].second <= (arr[i+1].first - arr[i].first - 1)) {
        can = (arr[i+1].first - arr[i].first - 1)-arr[i].second >= arr[i+1].second;
        ans = max(ans, 1+solve(i+1, can));
    }

    return dp[i][canDropBefore] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    memset(dp, -1, sizeof dp);

    cin >> n;
    arr = vector<pair<int, int>>(n);
    for(auto &i : arr)
        cin >> i.first >> i.second;
    
    if(n <= 2) {
        cout << n << "\n";
        return 0;
    }

    int ans = 2;
    ans += solve(1, (arr[1].first - arr[0].first - 1) >= arr[1].second);

    cout << ans << "\n";

    return 0;
}