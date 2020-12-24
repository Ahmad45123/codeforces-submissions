#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, p, k; cin >> n >> p >> k;
        string s; cin >> s;
        ll x, y; cin >> x >> y;

        vector<int> cntMods(k);
        ll ans = 1e18;
        for(int i = n, cnt = 1; i >= p; i--, cnt ++) {
            if(s[i-1] == '0')
                cntMods[i%k] ++;
            if(cnt <= n-p+1)
                ans = min(ans, x*cntMods[i%k]+y*(i-p));
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}