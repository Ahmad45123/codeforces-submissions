#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        if(n == 1) {
            cout << -1 << "\n";
            continue;
        }
        string ans = "2";

        for(int i = 0; i < n - 1; i++) {
            ans += '3';
        }

        cout << ans << "\n";
    }
    
    return 0;
}