#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

ll invMod(ll x, ll y) {
    ll ans = (-x)%y;
    if(ans < 0)
        ans += y;
    return ans%y;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        ll sum = 0;
        for(int &x : arr) {
            cin >> x;
            sum += x;
        }

        ll mx = *max_element(arr.begin(), arr.end());

        cout << max(invMod(sum, n-1), mx*(n-1) - sum) << "\n";
    }

    return 0;
}