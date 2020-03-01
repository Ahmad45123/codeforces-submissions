#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int s; cin >> s;
        int ans = 0;
        while(s > 0) {
            int toSpend = s - s%10;
            if(s <= 9)
                toSpend = s;
            s -= toSpend;
            s += (toSpend / 10);
            ans += toSpend;
        }
        cout << ans << "\n";
    }
    
    return 0;
}