#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<vector<int>> arr;
int dp[71][71][36][71];

int solve(int i, int j, int passed, int smmod) {
    if(j >= m) {
        i ++;
        j = 0;
        passed = 0;
    }
    if(i >= n)
        return 0;
    if(~dp[i][j][passed][smmod])
        return dp[i][j][passed][smmod];

    int ans = 0;

    if((smmod + solve(i, j+1, passed, smmod)) % k == 0)
        ans = max(ans, solve(i, j+1, passed, smmod));
        
    if((passed < m/2) && (smmod + arr[i][j] + solve(i, j+1, passed+1, (smmod+arr[i][j])%k)) % k == 0)
        ans = max(ans, arr[i][j] + solve(i, j+1, passed+1, (smmod+arr[i][j])%k));

    return dp[i][j][passed][smmod] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> k;
    arr = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    memset(dp, -1, sizeof dp);

    cout << solve(0, 0, 0, 0) << "\n";

    return 0;
}