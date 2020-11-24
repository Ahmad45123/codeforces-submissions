#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> arr(n+1);
        for(int i = 1; i <= n; i++)
            arr[i].push_back(0);
        for(int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            arr[tmp].push_back(i);
        }
        for(int i = 1; i <= n; i++)
            arr[i].push_back(n+1);

        int ans = 1e9;
        for(int i = 1; i <= n; i++) {
            if(arr[i].size() > 2) {
                int tmp = 0;
                for(int j = 1; j < arr[i].size(); j++)
                    tmp += (arr[i][j]-arr[i][j-1]-1 > 0 ? 1 : 0);
                ans = min(tmp, ans);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}