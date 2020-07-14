#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<ll> arr(n);
        for(ll &x : arr)
            cin >> x;

        sort(arr.begin(), arr.end(), greater<int>());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ll tmp = arr[i];
            ll z = 1;
            while(tmp < x) {
                i ++;
                z ++;
                if(i >= n)
                    break;
                tmp = arr[i]*z;
            }
            if(tmp >= x) ans ++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}