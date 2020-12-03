#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> arr;
vector<vector<vector<int>>> dp;

int solve(int i, int prev, int cx) {
    if(i >= arr.size())
        return 0;

    if(~dp[i%2][prev][cx])
        return dp[i%2][prev][cx];

    int ans = 1e9;

    if(prev <= arr[i])
        ans = min(ans, solve(i+1, arr[i], cx));
    if(prev <= cx && cx < arr[i])
        ans = min(ans, 1+solve(i+1, cx, arr[i]));
    
    return dp[i%2][prev][cx] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        arr = vector<int>(n);
        dp = vector<vector<vector<int>>>(2, vector<vector<int>>(501, vector<int>(501, -1)));
        for(int &i : arr)
            cin >> i;

        if(n == 1) {
            cout << "0\n";
            continue;
        }

        int ans = solve(1, arr[0], x);
        if(arr[0] > x)
            ans = min(ans, 1+solve(1, x, arr[0]));

        cout << (ans == 1e9 ? -1 : ans) << "\n";
    }
    
    return 0;
}