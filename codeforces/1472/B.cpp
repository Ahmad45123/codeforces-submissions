#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int nTwos = 0, nOnes = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x == 1)
                nOnes ++;
            else
                nTwos ++;
        }

        if(nTwos % 2 == 1) {
            nOnes -= 2;
        }
        if(nOnes < 0) {
            cout << "NO\n";
            continue;
        }

        cout << (nOnes % 2 == 0 ? "YES\n" : "NO\n");
    }
    
    return 0;
}