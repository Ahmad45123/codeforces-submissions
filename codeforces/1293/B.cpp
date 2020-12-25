#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    double ans = 0;
    while(n >= 1) {
        ans += 1.0/n;
        n --;
    }
    cout << fixed << setprecision(5) << ans << "\n";
    
    return 0;
}