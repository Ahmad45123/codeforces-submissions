#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(2*n);
    for(ll &x : arr)
        cin >> x;
    
    sort(arr.begin(), arr.end());
    
    ll ans = (arr[n-1]-arr[0])*(arr[2*n-1]-arr[n]);
    for(int i = 1; i < n; i++) {
        ans = min(ans, (arr[2*n-1]-arr[0])*(arr[i+n-1]-arr[i]));
    }
    cout << ans << "\n";

    return 0;
}