#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        ll ans = 1e9;
        for(int x = 1; x <= 100; x ++) {
            ll tmp = 0;
            ll prev = -1e9;
            for(int i = 0; i < n; i++) {
                if(arr[i] != x && i-prev+1 > k) {
                    tmp ++;
                    prev = i;
                }
            }
            ans = min(ans, tmp);
        }
        cout << ans << "\n";
    }
    
    return 0;
}