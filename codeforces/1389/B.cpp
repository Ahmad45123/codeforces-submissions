#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> arr;
int dp[100001][6][2];

int solve(int i, int k, int z, bool t) {
    if(i >= n)
        return 0;
    if(k <= 0)
        return 0;
    if(~dp[i][z][t])
        return dp[i][z][t];
    
    int ans = 0;
    if(i+1 < n)
        ans = arr[i+1]+solve(i+1, k-1, z, false);
    if(!t && i > 0 && z > 0) {
        ans = max(ans, arr[i-1]+solve(i-1, k-1, z-1, true));
    }

    return dp[i][z][t] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int k, z; cin >> n >> k >> z;
        
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= z; j++)
                for (int left = 0; left < 2; left++)
                    dp[i][j][left] = -1;
        
        arr = vector<int>(n);
        for(int &x : arr)
            cin >> x;       

        cout << arr[0]+solve(0, k, z, false) << "\n";
    }
    
    return 0;
}