#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> arrN;
int m;
vector<int> arrM;
vector<vector<int>> dp;

int solve(int i, int j) {
    if(i >= n && j >= m)
        return 0;
    if(~dp[i][j])
        return dp[i][j];

    int ans = 0;
    if(i < n) {
        ans = max(ans, arrN[i] + solve(i+1, j));
    }
    if(j < m) {
        ans = max(ans, arrM[j] + solve(i, j+1));
    }

    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        arrN = vector<int>(n);
        for(int &x : arrN)
            cin >> x;
        cin >> m;
        arrM = vector<int>(m);
        for(int &x : arrM)
            cin >> x;
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));

        cout << max(0, solve(0, 0)) << "\n";
    }
    
    return 0;
}