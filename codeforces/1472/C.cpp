#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        vector<bool> vis(n);

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            ll tmp = 0;
            for(int j = i; j < n; j += arr[j]) {
                if(vis[j]) break;
                tmp += arr[j];
                ans = max(ans, tmp);
                vis[j] = true;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}