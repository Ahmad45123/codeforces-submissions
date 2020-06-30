#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x %= k;
            if(x != 0)
                mp[k - x] ++;
        }

        ll ans = 0;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans = max(ans, 1LL+it->first+((it->second-1)*k));
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}