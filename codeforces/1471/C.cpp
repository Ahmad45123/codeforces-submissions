#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> ks(n+1);
        vector<ll> prices(m+1);
        for(int i = 1; i <= n; i++)
            cin >> ks[i];
        for(int i = 1; i <= m; i++)
            cin >> prices[i];

        vector<ll> reversed(m+1);
        for(int i = 1; i <= n; i++) {
            reversed[ks[i]] ++;
        }

        ll ans = 0;

        int j = 1;
        for(int i = m; i >= 1; i--) {
            while(reversed[i] > 0 && prices[j] < prices[i] && j < i) {
                ans += prices[j];
                j ++;
                reversed[i] --;
            }
            ans += reversed[i]*prices[i];
        }

        cout << ans << "\n";
    }
    
    return 0;
}