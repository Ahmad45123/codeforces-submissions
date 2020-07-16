#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    double a, b, c, d; cin >> a >> b >> c >> d;


    double ans = a/b;
    for(int i = 1; i <= 1e5; i++) {
        ans += pow(1-a/b, i)*pow(1-c/d, i)*(a/b);
    }

    cout << fixed << setprecision(8) << ans << "\n";
    
    return 0;
}