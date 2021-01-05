#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m; 
vector<int> ks;
vector<ll> prices;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        ks = vector<int>(n+1);
        prices = vector<ll>(m+1);
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
            while(reversed[i] > 0 && j < i) {
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