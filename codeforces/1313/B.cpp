#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x, y; cin >> n >> x >> y;
        int maxPlace = min(n, max(1, x+y-1));
        int minPlace = min(n, max(1, x+y+1-n));
        cout << minPlace << " " << maxPlace << "\n";
    }
    
    return 0;
}