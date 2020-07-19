#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        ll l, r, m; cin >> l >> r >> m;
        ll sz = r-l;
        ll a, b, c;

        for(int x = l; x <= r; x++) {
            int md = m % x;
            int el = x-md;
            if(md <= sz && m-md != 0) {
                a = x;
                b = l+md;
                c = l;
            } else if(el <= sz) {
                a = x;
                b = l;
                c = l+el;
            }
        }

        cout << a << " " << b << " " << c << "\n";

    }

    return 0;
}