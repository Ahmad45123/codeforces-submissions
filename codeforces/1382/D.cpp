#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<vector<short>> dp;
vector<int> arr;
vector<int> sums;

bool isPossible(int i, int sm) {
    if(sm == 0)
        return true;
    if(i >= sums.size())
        return false;
    if(~dp[i][sm])
        return dp[i][sm];

    if(sm-sums[i] < 0)
        return dp[i][sm] = isPossible(i+1, sm);
    return dp[i][sm] = (isPossible(i+1, sm) || isPossible(i+1, sm-sums[i]));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        sums.clear();
        dp = vector<vector<short>>(2*n+1, vector<short>(n+1, -1));
        arr = vector<int>(2*n);
        int positions[4002];
        for(int i = 0; i < 2*n; i++) {
            cin >> arr[i];
            positions[arr[i]] = i+1;
        }
        
        int prev = 2*n+1;
        for(int i = 2*n; i > 0; i--) {
            if(positions[i] <= prev) {
                sums.push_back(prev-positions[i]);
                prev = positions[i];
            }
        }

        cout << (isPossible(0, n) ? "YES\n" : "NO\n");
    }
    
    return 0;
}