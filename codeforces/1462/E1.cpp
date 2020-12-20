#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll C(ll n, ll k) {
    ll res = 1;
    for (ll i = n - k + 1; i <= n; ++i)
        res *= i;
    for (ll i = 2; i <= k; ++i)
        res /= i;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //modulo::mod(1e9+7);

    int t; cin >> t;
    while(t--) {
        int n, m = 3, k = 2; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        sort(arr.begin(), arr.end());

        ll ans = 0;

        for(int i = n-1; i >= 0; i --) {
            auto it = lower_bound(arr.begin(), arr.end(), arr[i]-k)-arr.begin();
            int cnt = i-it;
            ans += C(cnt, m-1);
        }

        cout << ans << "\n";
    }
    
    return 0;
}