#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll d, k; cin >> d >> k;
        ll x = 0, y = 0;
        bool p = false;
        while(x*x+y*y <= d*d) {
            if(x < y)
                x += k;
            else
                y += k;
            p = !p;
        }
        cout << (p ? "Utkarsh\n" : "Ashish\n");
    }
    
    return 0;
}