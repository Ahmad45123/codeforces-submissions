#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        vector<int> count(2*n+5);
        for(int &x : arr) {
            cin >> x;
            count[x] ++;
        }

        for(int i = 2*n; i >= 1; i--) {
            if(count[i] > 0 && count[i+1] == 0) {
                count[i+1] ++;
                count[i] --;
            }
        }

        int ans = 0;
        for(int i = 2*n+2; i >= 1; i--) {
            if(count[i] > 0) {
                ans ++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}