#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        int lx = -1e5, rx = 1e5, dy = -1e5, uy = 1e5;
        for(int i = 0; i < n; i++) {
            int x, y, f1, f2, f3, f4; cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if(!f1) {
                lx = max(lx, x);
            }
            if(!f3) {
                rx = min(rx, x);
            }
            if(!f4) {
                dy = max(dy, y);
            }
            if(!f2) {
                uy = min(uy, y);
            }
        }

        if(lx <= rx && dy <= uy) {
            cout << 1 << " " << (rx+lx)/2 << " " << (uy+dy)/2 << "\n";
        } else {
            cout << "0\n";
        }
    }
    
    return 0;
}