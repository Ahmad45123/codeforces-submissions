#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(i*2 <= n) {
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}