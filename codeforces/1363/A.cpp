#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        int nOdd = 0, nEven = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x % 2 == 0)
                nEven ++;
            else
                nOdd ++;
        }

        bool possible = false;

        for(int i = 1; i <= min(nOdd, x); i += 2) {
            if(i+nEven >= x) {
                possible = true;
            }
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
    
    return 0;
}