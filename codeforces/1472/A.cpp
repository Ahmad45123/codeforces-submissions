#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int w, h, n; cin >> w >> h >> n;
        ll pwr = 0;
        while(w % 2 == 0 || h % 2 == 0) {
            if(w % 2 == 0) {
                pwr ++;
                w /= 2;
            } else if(h % 2 == 0) {
                pwr ++;
                h /= 2;
            } else {
                break;
            }
        }
        if((1LL << pwr) >= n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    
    return 0;
}