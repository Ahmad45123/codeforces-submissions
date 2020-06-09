#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, q; cin >> a >> b >> q;
        vector<int> arr(a*b+1, 0);
        for(int i = 1; i < a*b; i++) {
            if((i%a)%b != (i%b)%a) arr[i] = 1;
        }
        for(int i = 1; i <= a*b; i++)
            arr[i] += arr[i-1];
        
        while(q--) {
            ll l, r; cin >> l >> r;
            l --;

            ll countr = r/(a*b);
            ll remr = r%(a*b);
            ll ans = arr[a*b-1]*countr + arr[remr];

            ll countl = l/(a*b);
            ll reml = l%(a*b);
            ans -= (arr[a*b-1]*countl + arr[reml]);
            
            cout << ans << " ";
        }
        cout << "\n";
    }
    
    return 0;
}