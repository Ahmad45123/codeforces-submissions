#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int nOdd1 = -1;
        int nOdd2 = -1;
        bool good = false;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x % 2 == 0 && !good) {
                cout << 1 << "\n" << i+1 << "\n";
                good = true;
            } else {
                if(nOdd1 == -1) nOdd1 = i;
                else if(nOdd2 == -1) nOdd2 = i;
            }
        }

        if(!good)
            if(nOdd1 != -1 && nOdd2 != -1) {
                cout << 2 << "\n" << nOdd1+1 << " " << nOdd2+1 << "\n";
            } else {
                cout << -1 << "\n";
            }
    }

    return 0;
}