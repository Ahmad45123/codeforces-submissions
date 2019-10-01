#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> prices(n);
        int origSum = 0;
        for(int i = 0; i < n; i++) {
            cin >> prices[i];
            origSum += prices[i];
        }

        int price = 0;
        for(int i = 1;; i++) {
            if(i*n >= origSum) {
                price = i;
                break;
            }
        }

        cout << price << "\n";
    }
    
    return 0;
}