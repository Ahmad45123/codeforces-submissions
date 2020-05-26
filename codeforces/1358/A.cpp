#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        if(n < m)
            swap(n, m);
        int ans = 0;
        if(n % 2 == 0)
            ans = m*(n/2);
        else {
            ans = m*(n-1)/2;
            ans += ceil(m*1.0/2.0);
        }
        cout << ans << "\n";
    }
    
    return 0;
}