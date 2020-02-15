#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
      int x, y, a, b; cin >> x >> y >> a >> b;
      int ans = (y-x)/(a+b);
      if(ans*a+x==y-b*ans) {
        cout << ans << "\n";
      } else {
        cout << -1 << "\n";
      }
    }

    return 0;
}