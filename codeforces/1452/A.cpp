#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x, y; cin >> x >> y;
        cout << x+y+max(0, abs(x-y)-1) << "\n";
    }
    
    return 0;
}